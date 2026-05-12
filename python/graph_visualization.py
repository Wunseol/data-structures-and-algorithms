"""
图可视化
使用 networkx + matplotlib 可视化图结构，展示 BFS/DFS 遍历顺序和最小生成树
"""

from collections import deque

try:
    import matplotlib.pyplot as plt
    import networkx as nx

    HAS_VIS = True
except ImportError:
    HAS_VIS = False
    print("=" * 60)
    print("缺少依赖库，请安装:")
    print("  pip install networkx matplotlib")
    print("=" * 60)


def create_undirected_graph() -> nx.Graph:
    G = nx.Graph()
    edges = [
        ("A", "B", 4), ("A", "C", 2), ("B", "C", 1),
        ("B", "D", 5), ("C", "D", 8), ("C", "E", 10),
        ("D", "E", 2), ("D", "F", 6), ("E", "F", 3),
    ]
    for u, v, w in edges:
        G.add_edge(u, v, weight=w)
    return G


def create_directed_graph() -> nx.DiGraph:
    G = nx.DiGraph()
    edges = [
        ("A", "B", 3), ("A", "C", 6), ("B", "C", 4),
        ("B", "D", 4), ("B", "E", 11), ("C", "D", 8),
        ("C", "E", 7), ("D", "E", 2), ("D", "F", 5),
        ("E", "F", 3),
    ]
    for u, v, w in edges:
        G.add_edge(u, v, weight=w)
    return G


def create_weighted_graph() -> nx.Graph:
    G = nx.Graph()
    edges = [
        (0, 1, 7), (0, 3, 5), (1, 2, 8), (1, 3, 9),
        (1, 4, 7), (2, 4, 5), (3, 4, 15), (3, 5, 6),
        (4, 5, 8), (4, 6, 9), (5, 6, 11),
    ]
    for u, v, w in edges:
        G.add_edge(u, v, weight=w)
    return G


def bfs_order(G: nx.Graph, start) -> list:
    visited = set()
    order = []
    queue = deque([start])
    visited.add(start)
    while queue:
        node = queue.popleft()
        order.append(node)
        for neighbor in sorted(G.neighbors(node)):
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)
    return order


def dfs_order(G: nx.Graph, start) -> list:
    visited = set()
    order = []

    def _dfs(node):
        visited.add(node)
        order.append(node)
        for neighbor in sorted(G.neighbors(node)):
            if neighbor not in visited:
                _dfs(neighbor)

    _dfs(start)
    return order


def kruskal_mst(G: nx.Graph) -> list[tuple]:
    edges = [(u, v, d["weight"]) for u, v, d in G.edges(data=True)]
    edges.sort(key=lambda x: x[2])
    parent = {node: node for node in G.nodes()}

    def find(x):
        while parent[x] != x:
            parent[x] = parent[parent[x]]
            x = parent[x]
        return x

    def union(a, b):
        ra, rb = find(a), find(b)
        if ra != rb:
            parent[ra] = rb
            return True
        return False

    mst = []
    for u, v, w in edges:
        if union(u, v):
            mst.append((u, v, w))
    return mst


def draw_graph(G, title: str, pos=None, node_colors=None, edge_colors=None, edge_widths=None):
    if not HAS_VIS:
        return
    fig, ax = plt.subplots(figsize=(8, 6))
    if pos is None:
        pos = nx.spring_layout(G, seed=42)

    if node_colors is None:
        node_colors = ["#4FC3F7"] * G.number_of_nodes()
    if edge_colors is None:
        edge_colors = ["#90A4AE"] * G.number_of_edges()
    if edge_widths is None:
        edge_widths = [1.5] * G.number_of_edges()

    is_directed = isinstance(G, nx.DiGraph)
    nx.draw_networkx_nodes(G, pos, node_color=node_colors, node_size=600, ax=ax)
    nx.draw_networkx_labels(G, pos, font_size=10, font_weight="bold", ax=ax)
    nx.draw_networkx_edges(
        G, pos, edge_color=edge_colors, width=edge_widths,
        arrows=is_directed, arrowsize=15, ax=ax,
    )

    weight_labels = nx.get_edge_attributes(G, "weight")
    if weight_labels:
        nx.draw_networkx_edge_labels(G, pos, edge_labels=weight_labels, font_size=8, ax=ax)

    ax.set_title(title, fontsize=14, fontweight="bold")
    ax.axis("off")
    fig.tight_layout()


def demo_basic_graphs():
    if not HAS_VIS:
        return

    G_undirected = create_undirected_graph()
    pos_spring = nx.spring_layout(G_undirected, seed=42)
    pos_circular = nx.circular_layout(G_undirected)

    draw_graph(G_undirected, "无向图 (Spring Layout)", pos=pos_spring)
    draw_graph(G_undirected, "无向图 (Circular Layout)", pos=pos_circular)

    G_directed = create_directed_graph()
    draw_graph(G_directed, "有向图 (Spring Layout)")


def demo_traversal():
    if not HAS_VIS:
        return

    G = create_undirected_graph()
    pos = nx.spring_layout(G, seed=42)

    bfs = bfs_order(G, "A")
    dfs = dfs_order(G, "A")

    print("BFS 遍历顺序:", " → ".join(bfs))
    print("DFS 遍历顺序:", " → ".join(dfs))

    bfs_color_map = {node: idx for idx, node in enumerate(bfs)}
    dfs_color_map = {node: idx for idx, node in enumerate(dfs)}

    cmap = plt.cm.Blues
    bfs_colors = [cmap(0.2 + 0.7 * bfs_color_map[n] / max(len(bfs) - 1, 1)) for n in G.nodes()]
    dfs_colors = [cmap(0.2 + 0.7 * dfs_color_map[n] / max(len(dfs) - 1, 1)) for n in G.nodes()]

    draw_graph(G, f"BFS 遍历顺序: {' → '.join(bfs)}", pos=pos, node_colors=bfs_colors)
    draw_graph(G, f"DFS 遍历顺序: {' → '.join(dfs)}", pos=pos, node_colors=dfs_colors)


def demo_mst():
    if not HAS_VIS:
        return

    G = create_weighted_graph()
    pos = nx.spring_layout(G, seed=42)

    mst_edges = kruskal_mst(G)
    mst_edge_set = {(u, v) for u, v, _ in mst_edges} | {(v, u) for u, v, _ in mst_edges}

    print("最小生成树边 (Kruskal):")
    total_weight = 0
    for u, v, w in mst_edges:
        print(f"  {u} -- {v} (权重: {w})")
        total_weight += w
    print(f"  总权重: {total_weight}")

    edge_colors = ["#E53935" if (u, v) in mst_edge_set else "#BDBDBD" for u, v in G.edges()]
    edge_widths = [3.0 if (u, v) in mst_edge_set else 1.0 for u, v in G.edges()]

    draw_graph(G, f"最小生成树 (总权重: {total_weight})", pos=pos, edge_colors=edge_colors, edge_widths=edge_widths)


def main():
    if not HAS_VIS:
        return

    demo_basic_graphs()
    demo_traversal()
    demo_mst()

    plt.show()


if __name__ == "__main__":
    main()
