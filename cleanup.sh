make clean
find . -name '.deps' -print0 | xargs -0 rm -R
find . -name '.dirstamp' -print0 | xargs -0 rm
rm Makefile
rm Makefile.in
rm -R */Makefile
rm -R */Makefile.in
rm Doxyfile
rm "stamp-h1"
rm configure
rm config.*
rm aclocal.m4
rm -R autom4te.cache
rm -R html
rm -R latex