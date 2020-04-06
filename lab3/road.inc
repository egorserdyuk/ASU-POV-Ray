#macro Street_0(  Street_Width,  //
                  Street_Length, //
                  Stripes_Width, //
                  Stripes_Len
                ) //-------------------
//-------------------------------------
#ifndef( Stripes_Texture )
#declare Stripes_Texture =
texture{ pigment{ color rgb<1,1,1>*1.1}
         finish { diffuse 0.9 phong 0.5}
       } // end of texture
#end //--------------------------------
#ifndef( Street_Texture )
#declare Street_Texture =
texture{ pigment{ color rgb<1,1,1>*.3}
         normal { bumps 0.5 scale 0.005}
         finish { diffuse 0.9 phong 0.1}
       } // end of texture
#end //--------------------------------
#local D = 0.001;
//-------------------------------------
union{
box{ < -Street_Width/2, 0, 0 >,
     < Street_Width/2, D, Street_Length>
     texture{Street_Texture}
   } // end of box --------------------
 #local Number_of_Stripes =
   int(Street_Length/(2*Stripes_Len));
 #local Nr = 0; //start
 #local EndNr=Number_of_Stripes;//end
 #while (Nr< EndNr)
 box{ <-Stripes_Width/2,   0, 0>,
      < Stripes_Width/2,2*D,Stripes_Len>
      texture{ Stripes_Texture}
      translate<0,0,Nr*2*Stripes_Len>
    } // end of box
 #local Nr = Nr + 1;  // next Nr
 #end // -------- end of loop
} // end of union
#end//-------------------- end of macro
//----------------- end of include file
object{ Street_0 (   6, // Width,
                   100, // Length,
                  0.10, // Stripes_W,
                  1.00, // Stripes_Len
                 ) //-----------------
        translate<3,0,-20>
        rotate<0, 90, 0>}