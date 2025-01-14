# Pure numeric data
perl -le 'foreach (0..20) {print 100*rand}' > num.txt

# Pure alphabetic (a..z, A..Z) data
perl -le '@x=(65..90,97..122); foreach $i (1..20){ foreach $j (1..20) {$s .= chr $x[int rand(52)]} print $s; $s="" }' > alpha.txt

# Alphabetic lower case data (a..z)
perl -le '@x=(97..122); foreach $i (1..20){ foreach $j (1..20) {$s .= chr $x[int rand(26)]} print $s; $s="" }' > alphalc.txt

# Alphabetic upper case data (A..A)
perl -le '@x=(65..90); foreach $i (1..20){ foreach $j (1..20) {$s .= chr $x[int rand(26)]} print $s; $s="" }' > alphauc.txt

# Delimited file with both numeric and alphabetic data
perl -e '@x=(65..90,97..122); foreach $i (1..20){ foreach $j (1..20) {$s .= chr $x[int rand(52)]} printf("%d|%s\n", 1000*rand, $s); $s="" }' > delimited.txt


