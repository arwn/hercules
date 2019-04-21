(use posix)

(define escape-codes
  `("\033[2J" ; clear screen
    "\033[1m" ;bold
    "\033[4m" ;underscore
    "\033[5m" ;blink
    "\033[7m" ;reverse video on
    "\033[8m" ;concealed on

    "\033[30m" ;black
    ;"\033[31m" ;red
    ;"\033[32m" ;green
    ;"\033[33m" ;yellow
    ;"\033[34m" ;blue
    ;"\033[35m" ;magenta
    ;"\033[36m" ;cyan
    ;"\033[37m" ;white

    ;"\033[40m" ;black
    ;"\033[41m" ;red
    ;"\033[42m" ;green
    ;"\033[43m" ;yellow
    ;"\033[44m" ;blue
    ;"\033[45m" ;magenta
    ;"\033[46m" ;cyan
    ;"\033[47m" ;white

    "\033[=0h" ;40x25 monochrome

    "\033[A" ;cursor up one line
    "\033[B" ;cursor down one line
    "\033[C" ;cursor right one char
    "\033[D" ;cursor left one char
    "\033[I" ;reverse line feed
    "\033[H" ;cursor to upper left corner
    "\033[I" ;reverse line feed
    "\033[H" ;cursor to upper left corner

    "\033[0A" ;arrow up
    "\033[0B" ;arrow down
    "\033[0C" ;arrow right
    "\033[0D" ;arrow left

    "\b" ;bell
    "\t" ;tab
    ))

(define (random-escape)
 (list-ref escape-codes (random (length escape-codes))))

(define (annoy)
  (display (random-escape))
  (flush-output) ;otherwise sleep hangs
  (sleep 10)
  (annoy))

(if (= 0 (process-fork))
    (annoy)
    (display "done!\n"))
