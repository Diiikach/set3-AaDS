import os
import os.path

import matplotlib.pyplot as plt
import numpy as np


SOLUTION_FILE = "/Users/dikach/Documents/algo-2025-1-semest/set3/a1.cpp"


def plot_bar_chart(
    labels,
    values,
    title="Сравнение значения площади",
    xlabel="K (количество бросков)",
    ylabel="S (площадь)",
    step=10
):
    fig, ax = plt.subplots(figsize=(10, 10), dpi=100)

    x = np.arange(len(labels))

    ax.bar(x, values, color=None, alpha=0.9)

    ax.set_xlabel(xlabel)
    ax.set_ylabel(ylabel)
    ax.set_title(title, fontsize=16)

    tick_positions = x[::step]
    tick_labels = [labels[i] for i in tick_positions]

    ax.set_xticks(tick_positions)
    ax.set_xticklabels(tick_labels, rotation=25, ha="right")

    ax.grid(axis="y", alpha=0.4)

    plt.tight_layout()
    plt.show()



os.system(f"clang++ {SOLUTION_FILE} -DTEST -o solution")

def test(k: int):
    with open("a1.data.txt", "w") as file:
        file.write(str(k) + "\n")
        file.write("""1.0 1.0 1.0\n1.5 2 1.1180339\n2.0 1.5 1.1180339""")
    os.system("./solution < a1.data.txt > ans.txt")
    with open("ans.txt", "r") as file:
        return float(file.read())


kvalues = [i for i in range(100, 100001, 500)]
results = [test(i) for i in kvalues]

plot_bar_chart(kvalues, results, step=10)
