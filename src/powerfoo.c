#include <foo/foo.h>


int  powerfoo_version()
{
   if( foo_version != 1848)
      return( -1);
   return( 1848);
}

