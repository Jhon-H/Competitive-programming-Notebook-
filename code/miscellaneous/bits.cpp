mask |= (1<<n) // PRENDER BIT-N
mask ^= (1<<n) // FLIPPEAR BIT-N
mask &= ~(1<<n) // APAGAR BIT-N
if(mask&(1<<n)) // CHECKEAR BIT-N