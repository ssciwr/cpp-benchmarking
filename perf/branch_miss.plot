set terminal png
set output 'branch_miss.png'
set title "Branch misses vs N"
set logscale xy
set xlabel "N"
set ylabel "branch miss %"
set yrange [0.005:100]
p \
200/(1+x) lt 0 lc 0 t "", \
'bench5_branch_miss.txt' u 1:(100*$2/$3) w lp t "bench5", \
'bench6_branch_miss.txt' u 1:(100*$2/$3) w lp t "bench6"
