"""
哈希表 ASL (Average Search Length) 分析
模拟链地址法和开放定址法（线性探测）在不同装载因子下的查找性能
"""

import random
import math


class ChainingHashTable:
    def __init__(self, size: int):
        self.size = size
        self.table: list[list[int]] = [[] for _ in range(size)]

    def _hash(self, key: int) -> int:
        return key % self.size

    def insert(self, key: int):
        idx = self._hash(key)
        self.table[idx].append(key)

    def search(self, key: int) -> tuple[bool, int]:
        idx = self._hash(key)
        comparisons = 0
        for item in self.table[idx]:
            comparisons += 1
            if item == key:
                return True, comparisons
        return False, comparisons


class LinearProbingHashTable:
    def __init__(self, size: int):
        self.size = size
        self.table: list[int | None] = [None] * size
        self.count = 0

    def _hash(self, key: int) -> int:
        return key % self.size

    def insert(self, key: int):
        idx = self._hash(key)
        while self.table[idx] is not None:
            idx = (idx + 1) % self.size
        self.table[idx] = key
        self.count += 1

    def search(self, key: int) -> tuple[bool, int]:
        idx = self._hash(key)
        comparisons = 0
        start = idx
        while True:
            comparisons += 1
            if self.table[idx] == key:
                return True, comparisons
            if self.table[idx] is None:
                return False, comparisons
            idx = (idx + 1) % self.size
            if idx == start:
                return False, comparisons


def simulate_chaining(table_size: int, num_keys: int, num_trials: int = 3) -> dict:
    load_factor = num_keys / table_size
    successful_total = 0
    successful_count = 0
    unsuccessful_total = 0
    unsuccessful_count = 0

    for _ in range(num_trials):
        ht = ChainingHashTable(table_size)
        keys = random.sample(range(table_size * 100), num_keys)
        for k in keys:
            ht.insert(k)

        for k in keys:
            found, cmp = ht.search(k)
            if found:
                successful_total += cmp
                successful_count += 1

        for _ in range(num_keys):
            probe = random.randint(table_size * 100, table_size * 200)
            found, cmp = ht.search(probe)
            unsuccessful_total += cmp
            unsuccessful_count += 1

    asl_success = successful_total / successful_count if successful_count else 0
    asl_unsuccess = unsuccessful_total / unsuccessful_count if unsuccessful_count else 0

    if load_factor != 0:
        theoretical_success = 1 + load_factor / 2
        theoretical_unsuccess = load_factor + math.exp(-load_factor) if load_factor < 20 else load_factor
    else:
        theoretical_success = 1.0
        theoretical_unsuccess = 1.0

    return {
        "load_factor": load_factor,
        "table_size": table_size,
        "num_keys": num_keys,
        "asl_success": asl_success,
        "asl_unsuccess": asl_unsuccess,
        "theoretical_success": theoretical_success,
        "theoretical_unsuccess": theoretical_unsuccess,
    }


def simulate_linear_probing(table_size: int, num_keys: int, num_trials: int = 3) -> dict:
    load_factor = num_keys / table_size
    successful_total = 0
    successful_count = 0
    unsuccessful_total = 0
    unsuccessful_count = 0

    for _ in range(num_trials):
        ht = LinearProbingHashTable(table_size)
        keys = random.sample(range(table_size * 100), num_keys)
        for k in keys:
            ht.insert(k)

        for k in keys:
            found, cmp = ht.search(k)
            if found:
                successful_total += cmp
                successful_count += 1

        for _ in range(num_keys):
            probe = random.randint(table_size * 100, table_size * 200)
            found, cmp = ht.search(probe)
            unsuccessful_total += cmp
            unsuccessful_count += 1

    asl_success = successful_total / successful_count if successful_count else 0
    asl_unsuccess = unsuccessful_total / unsuccessful_count if unsuccessful_count else 0

    alpha = load_factor
    if alpha < 1.0 and alpha > 0:
        theoretical_success = 0.5 * (1 + 1 / (1 - alpha))
        theoretical_unsuccess = 0.5 * (1 + 1 / (1 - alpha) ** 2)
    elif alpha == 0:
        theoretical_success = 1.0
        theoretical_unsuccess = 1.0
    else:
        theoretical_success = float("inf")
        theoretical_unsuccess = float("inf")

    return {
        "load_factor": load_factor,
        "table_size": table_size,
        "num_keys": num_keys,
        "asl_success": asl_success,
        "asl_unsuccess": asl_unsuccess,
        "theoretical_success": theoretical_success,
        "theoretical_unsuccess": theoretical_unsuccess,
    }


def run_chaining_analysis():
    print("=" * 100)
    print("链地址法 (Chaining) ASL 分析")
    print("=" * 100)
    print(f"{'装载因子':<12} {'表大小':<10} {'键数量':<10} {'成功ASL(实测)':<16} {'成功ASL(理论)':<16} {'失败ASL(实测)':<16} {'失败ASL(理论)':<16}")
    print("─" * 100)

    load_factors = [0.5, 0.75, 1.0, 1.5, 2.0]
    table_size = 101

    for lf in load_factors:
        num_keys = int(table_size * lf)
        result = simulate_chaining(table_size, num_keys)
        print(
            f"{result['load_factor']:<12.2f} "
            f"{result['table_size']:<10} "
            f"{result['num_keys']:<10} "
            f"{result['asl_success']:<16.4f} "
            f"{result['theoretical_success']:<16.4f} "
            f"{result['asl_unsuccess']:<16.4f} "
            f"{result['theoretical_unsuccess']:<16.4f}"
        )

    print()


def run_linear_probing_analysis():
    print("=" * 100)
    print("开放定址法 - 线性探测 (Linear Probing) ASL 分析")
    print("=" * 100)
    print(f"{'装载因子':<12} {'表大小':<10} {'键数量':<10} {'成功ASL(实测)':<16} {'成功ASL(理论)':<16} {'失败ASL(实测)':<16} {'失败ASL(理论)':<16}")
    print("─" * 100)

    load_factors = [0.3, 0.5, 0.7, 0.9]
    table_size = 101

    for lf in load_factors:
        num_keys = int(table_size * lf)
        result = simulate_linear_probing(table_size, num_keys)
        ts = f"{result['theoretical_success']:.4f}" if result["theoretical_success"] != float("inf") else "∞"
        tu = f"{result['theoretical_unsuccess']:.4f}" if result["theoretical_unsuccess"] != float("inf") else "∞"
        print(
            f"{result['load_factor']:<12.2f} "
            f"{result['table_size']:<10} "
            f"{result['num_keys']:<10} "
            f"{result['asl_success']:<16.4f} "
            f"{ts:<16} "
            f"{result['asl_unsuccess']:<16.4f} "
            f"{tu:<16}"
        )

    print()


def main():
    run_chaining_analysis()
    run_linear_probing_analysis()

    print("=" * 100)
    print("理论公式:")
    print("  链地址法:")
    print("    成功 ASL = 1 + α/2")
    print("    失败 ASL ≈ α + e^(-α)  (泊松近似)")
    print("  线性探测:")
    print("    成功 ASL = ½(1 + 1/(1-α))")
    print("    失败 ASL = ½(1 + 1/(1-α)²)")
    print("  其中 α = 装载因子 = n/m (键数量/表大小)")
    print("=" * 100)


if __name__ == "__main__":
    main()
