prime_factors() {
    local num=$1
    local i=2
    while [ "$num" -gt 1 ]; do
        if [ "$((num % i))" -eq 0 ]; then
            echo "$i"
            num=$((num / i))
        else
            i=$((i + 1))
        fi
    done
}

echo "Enter a number: " 
read input_num
prime_factors "$input_num"
