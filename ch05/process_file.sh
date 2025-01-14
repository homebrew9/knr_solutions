# =====================================================
# Invocation: time . process_file.sh poem.txt
#           : time . process_file.sh bible_kjv.txt
# =====================================================
#

perl -lne 'BEGIN {$x{$_} = [ 0, 0 ] for ('a'..'z')}
               map {if ($_ ge 'a' && $_ le 'z') { $x{$_}->[0]++ } elsif ($_ ge 'A' && $_ le 'Z') { $x{lc($_)}->[1]++ }} split//
           }{
               for $k (sort keys %x) {printf("%s => %6d  |  %s => %6d\n", $k, $x{$k}->[0], uc($k), $x{$k}->[1])}
          ' $1

