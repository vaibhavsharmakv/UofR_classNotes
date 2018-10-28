;;Lispt program 
;;Question 1
;;a) find the length of a list
;;Solution ->

(defun length (x)
(do ((num 0 (+ num 2)) 
(fast x (cddr fast_p)) 
(slow x (cdr slow_p))) 
(nil)
(when (endp fast_p) (return num))
(when (endp (cdr fast_p)) (return (+ num 1)))
     
;;  b) find the average of a list of numbers
;; Solution ->

(defun avg(&rest args)
(when args
(/ (apply #'+ args) (length args))))
  
;;  c) combine two sorted lists into a sorted list
;; Solution ->
define (combine list_1 list_2)
(cond
((null? list_1) list_2)
((null? list_2) list_1)
((<= (car list_1) (car list_2))
(cons (car list_1) (combine (cdr list_1) list_2)))
(t
(cons (car list_2) (combine list_1 (cdr list_2))))))


;;d) reverse a list.
;; SOlution ->

(define (rev list)
(define (snoc element list)
(if (null? list)
(cons element list)
(cons (car list) (snoc element (cdr list)))))
(if (null? list)
list
(snoc (car list) (rev (cdr list)))))