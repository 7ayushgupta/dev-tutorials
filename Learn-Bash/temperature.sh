while true;
	do echo $( date '+%F %H:%M:%S' ): $( sensors | grep 'temp1' | sed -r 's/^.*: +(.*) +[(].*$/\1/' ) >> log.file; 
	sleep 1;
done


