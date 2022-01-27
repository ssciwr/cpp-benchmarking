#!/usr/bin/env python
# coding: utf-8

# to use:
# 1. generate a json file, e.g. ./build/bench/bench7 --benchmark_out=bench7.json
# 2. generate plots, e.g. ./plot.py bench7.json

import pandas as pd
import json
from matplotlib import pyplot as plt
import sys

filename = sys.argv[1]
basename = filename.split(".")[0]

# load benchmarks data
df = pd.DataFrame(json.load(open(filename))["benchmarks"])

# only keep names with /, i.e. drop avg/rms/etc entries
df = df.loc[df.name.str.contains("/")]

# create a column with complexity n
df["n"] = df.name.apply(lambda x: x.split("/")[1]).astype("uint32")

# create a column with simplified name
df["benchmark"] = df.name.apply(lambda x: x.split("<")[1])

# only keep name, cpu_time and n columns
df = df[["benchmark", "n", "cpu_time"]]

# plot results
fig, ax = plt.subplots(ncols=1, figsize=(12, 6))
for benchmark, data in df.groupby("benchmark"):
    data.plot(ax=ax, x="n", y="cpu_time", label=benchmark)
plt.title(basename)
plt.title(f"{basename} runtime")
plt.xscale("log")
plt.yscale("log")
plt.legend()
fig.savefig(f"{basename}.png", bbox_inches="tight", dpi=120)
