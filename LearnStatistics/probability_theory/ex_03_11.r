library(gtools)

perm = function(n, k) {
 v = prod((n-k+1):n)
 return(v)
}

birth_prob = function(N) { 1 - perm(365, N)/365^N }

