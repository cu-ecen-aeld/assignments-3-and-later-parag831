if [ $# -lt 2 ]
then
	echo "Not enough arguments"
	exit 1
fi

filesdir="$1"
searchstr="$2"

if [ ! -d "$filesdir" ]
then
	echo "argument 1 needs to be a directory"
	exit 1
else
	X=$(find "$filesdir" -type f | wc -l)
	Y=$(grep -r "$searchstr" "$filesdir" | wc -l)
	echo "The number of files are $X and the number of matching lines are $Y"
	exit 0 
fi

