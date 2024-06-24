read -p "Enter a Number: " n
a=1
for (( i=n ; i >=1 ; i-- ))
do
	((a=$a*i))
done
echo "The Factorial Of The Number $n is : $a "
