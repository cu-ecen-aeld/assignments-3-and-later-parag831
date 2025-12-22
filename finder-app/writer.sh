if [ $# -lt 2 ]
then 
	echo "not enough arguments"
	exit 1
fi

writefile="$1"
writestr="$2"

writedir=$(dirname "$writefile")
mkdir -p "$writedir"


echo "$writestr" > "$writefile"
exit 0
