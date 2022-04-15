first.len = function(x, y) {
  
  # new line is a separator 
  r = sqrt(x^2 + y^2)
  # return() works without a blank
  return(r)
}

first.is_even = function(n) {
  if ( n %% 2 == 0 ) 
  {
    return(TRUE)
  }
  return(FALSE)
}

for(i in 1:10) {
  x[i] = i
}


set.seed(110)

S = rep(NA, 100)
S[1] = rnorm(1, 0, 1)

for(i in 2:100) {
  S[i] = S[i-1] + rnorm(1, 0, 1)
}

plot(S, main = "S", type = "l", xlab = "i", col = "darkred", lwd = 3)

#line at 0
abline(h = 0, col = "black", lty = 3, lwd = 2)

set.seed(110)

x = -100:100
y = x^2

plot(x, y, col="darkred", xlab="x", ylab="x^2", type="l")

kilo_to_mile = function(x) {
  r = x / 1.60934 
  return (r)
}
