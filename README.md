This package does not contain any R code. It only contains two C functions to support the calling of functions passed in as external function pointers. The primary use case is when R is embedded in your program (D program in my case) and you want to write the objective function for an optimization problem in D. It works in other cases, of course, so you can pass a D function pointer and pointer to your data, and it can be called from R.

Link to funcptr.so.

`SEXP callfunction(SEXP ptr, SEXP par)`: ptr is a function pointer created with `R_MakeExternalPtr` and par is a vector of data (double precision). The function needs to return a `SEXP`. You can use this to evaluate an objective function for an optimization routine with an R function like this:

```
objfun <- function(par) {
	return(.Call("callfunction", funptr, par);
}
```

It is assumed that ptr has been passed into the R global environment and given the name funptr.

`SEXP callfunction2(SEXP ptr, SEXP par, SEXP dataptr)`: Same as the previous function, but with an additional argument that holds a `void *` pointer to other data. It might be a struct holding the observations for your dataset.
