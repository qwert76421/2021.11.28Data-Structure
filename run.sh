for i in "0.5"
do
    for time in $(seq 10 30)
    do 
        ./main.exe $time result2.csv $i
    done
done
