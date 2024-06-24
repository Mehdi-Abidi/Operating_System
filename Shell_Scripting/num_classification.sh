read -p "Enter a Number: " number

if [ "$number" -gt 0 ];
then
	echo "The Number Is +ve. "

elif [ "$number" -lt 0 ];
then
	echo "The Number Is -ve. "

else
	echo "The Number Is Zero. "
fi
