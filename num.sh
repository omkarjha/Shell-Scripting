clear
echo "Numbers 1 to 100"
i=1
while [ $i -le 100 ]
do
	echo "$i"
	i=$((i+1))
done
