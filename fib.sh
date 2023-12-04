clear
echo "Enter the number for the range of the series :"
read n
a=0
b=1


echo "Fibonacci series upto $n is :"

for i in {i . . $n}
	
do
	echo "$a"
	temp=$((a+b))
	a=$b
	b=$temp
done
