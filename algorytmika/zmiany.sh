#!/bin/zsh
arr=()
TIME=4
BROWSER="Firefox"
for i in $@; do
	case $i in
		-h) 
		echo '************************************'
		echo "HELP"
		echo '-h: pomoc'
		echo '-b=<name> or --browser=<name>: default browser to use'
		echo '-t=<time> or --time=<time>: time to wait between checks [sec]'
		echo '-o=<name> or --output=<name>: prefix to downloaded sites saves'
		echo '-i=<name> or --input=<name>: set input file with adresses'
		echo '-v: verbose'
		echo '-e: exit after detecting a change'
		echo '-l: save differences to log file (zmiany.log)'
		echo '-d: echo differences to display'
		echo
		echo '************************************'
		exit
		;;
		--browser=*|-b=*) BROWSER="${i#*=}" ;;
		--time=*|-t=*) TIME="${i#*=}" ;;
		--output=*|-o=*) OUTPUT="${i#*=}." ;;
		--input=*|-i=*) 
		while read LINE || [[ -n $LINE ]]; do
  		arr+=($LINE)
		done <"${i#*=}"
		;;
		-v) VERBOSE=YES ;;
		-e) EXIT=YES ;;
		-l) LOG=YES ;;
		-d) DISPLAY=YES ;;
		-*|--*) echo "invalid option: ${i#*=} " ; exit ;;
		*) arr+=($i) ;;
	esac
done
echo "Zaczynam!"
while [[ "YES" ]]; do
	for i in $arr; do
		if [[ ! $VERBOSE ]]; then
			wget -q -O "$OUTPUT$i" "$i"
		else
			wget -nv -O "$OUTPUT$i" "$i"
		fi
	done
	echo "Czekam ${TIME}s..."
	sleep "$TIME"
	for i in $arr; do
		if [[ ! $VERBOSE ]]; then
			wget -q -O "${OUTPUT}second.$i" "$i"
		else
			wget -nv -O "${OUTPUT}second.$i" "$i"
		fi
		WYNIK=$(diff $OUTPUT$i ${OUTPUT}second.$i)
		if [[ ! $WYNIK ]]; then
			echo "Nic się nie zmieniło w $i ;)"
		else
			echo "Cos jest inaczej w $i."
			ZOSTAN="YES"
			if [[ ! $DISPLAY ]] && [[ ! $LOG ]]; then; 
				open -a $BROWSER "http://$i"; fi
			if [[ $DISPLAY ]]; then; 
				echo $WYNIK; fi
			if [[ $LOG ]]; then
				echo "Saved to ${OUTPUT}$i.log"
				echo $WYNIK >"${OUTPUT}$i.log"
			fi
		fi
	done
	if [[ ! $ZOSTAN ]] || [[ $EXIT ]]; then
		break;
	fi
	echo "Powtarzam sprawdzanie."
done