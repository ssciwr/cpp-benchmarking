set terminal png
set output 'cache_miss.png'
set title "L1 data cache load misses vs N"
set logscale xy
set xlabel "N"
set ylabel "cache miss %"
p \
'bench5_cache_miss.txt' u 1:(100*$2/$3) w lp t "bench5", \
'bench6_cache_miss.txt' u 1:(100*$2/$3) w lp t "bench6"
