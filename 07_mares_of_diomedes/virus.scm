(use posix)

(define escape-codes
  `("\033[2J" ; clear screen
    "\033[1m" ;bold
    "\033[4m" ;underscore
    "\033[5m" ;blink
    "\033[7m" ;reverse video on
    "\033[8m" ;concealed on

    "\033[30m" ;black
    "\033[31m" ;red
    "\033[32m" ;green
    "\033[33m" ;yellow
    "\033[34m" ;blue
    "\033[35m" ;magenta
    "\033[36m" ;cyan
    "\033[37m" ;white

    "\033[40m" ;black
    "\033[41m" ;red
    "\033[42m" ;green
    "\033[43m" ;yellow
    "\033[44m" ;blue
    "\033[45m" ;magenta
    "\033[46m" ;cyan
    "\033[47m" ;white

    "\033[=0h" ;40x25 monochrome
    "\b" ;bell
    ))

(define (random-escape)
 (list-ref escape-codes (random (length escape-codes))))

(define (annoy)
  (display (random-escape))
  (flush-output) ;otherwise sleep hangs
  (sleep 1)
  (annoy))

(if (= 0 (process-fork))
    (annoy)
    (display "done!\n"))
