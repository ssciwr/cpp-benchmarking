for bench in 5 6
do
    echo "" > bench${bench}_cache_miss.txt
    for n in 2 4 8 16 32 64 128 256 512 1024 2048 4096
    do
        perf stat -e L1-dcache-loads,L1-dcache-load-misses -o tmpstat.txt ../build/bench/bench${bench} --benchmark_filter=".*:vec_map.*/$n\$" --benchmark_min_time=0.1
        COUNT=$(grep "L1-dcache-loads" tmpstat.txt | awk '{print $1}' | tr -d ,)
        MISS=$(grep "L1-dcache-load-misses" tmpstat.txt | awk '{print $1}' | tr -d ,)
        echo "$n ${MISS} ${COUNT}" >> bench${bench}_cache_miss.txt
    done
done
rm tmpstat.txt
gnuplot cache_miss.plot
