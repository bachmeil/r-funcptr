#include <R.h>
#include <Rinternals.h>

SEXP callfunction(SEXP ptr, SEXP par) {
	DL_FUNC f = R_ExternalPtrAddrFn(ptr);
	SEXP (*g)(SEXP) = (SEXP(*)(SEXP)) f;
	return g(par);
}

SEXP callfunction2(SEXP ptr, SEXP par, SEXP dataptr) {
	DL_FUNC f = R_ExternalPtrAddrFn(ptr);
	SEXP (*g)(SEXP, SEXP) = (SEXP(*)(SEXP, SEXP)) f;
	return g(par, dataptr);
}
