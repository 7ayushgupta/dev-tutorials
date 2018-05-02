echo -e "Hi, please type: \c"
read word
echo $word

echo "What are your favourite colors?"
read -a colors
# read to an array
echo "  My favourite colors are ${colors[0]}"