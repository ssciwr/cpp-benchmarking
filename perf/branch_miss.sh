for bench in 5 6
do
    echo "" > bench${bench}_branch_miss.txt
    for n in 2 4 8 16 32 64 128 256 512 1024 2048 4096
    do
        perf stat -e branches,branch-misses -o tmpstat.txt ../build/bench/bench${bench} --benchmark_filter=".*:vec_map.*/$n\$" --benchmark_min_time=0.1
        COUNT=$(grep "branches" tmpstat.txt | awk '{print $1}' | tr -d ,)
        MISS=$(grep "branch-misses" tmpstat.txt | awk '{print $1}' | tr -d ,)
        echo "$n ${MISS} ${COUNT}" >> bench${bench}_branch_miss.txt
    done
done
rm tmpstat.txt
gnuplot branch_miss.plot
