#declare w6=0;
#declare w5=30;
#declare w4=-70;
#declare w3=100;
#declare w2=-150;

#declare ww6=w6;
#declare ww5=w5;
#declare ww4=w4;
#declare ww3=w3;
#declare ww2=w2;

#declare i=0;

#macro tribe()

#declare i=i+1;

#if (i<6)
    tribe()
    tribe()
#end

cylinder{<0,0,0>,<0,1,0>,0.2,1.0 pigment{color rgb<0.99-i*0.05,0.35+i*0.08,0.35>}

         #if(i>5)
            scale <0.5,1.5,0.5>
            rotate <60,w6,0>
            translate y*1
         #end 
         #if(i>4)
            scale <0.8,1.0,0.8>
            rotate <60,w5,0>
            translate y*1
         #end            
         #if(i>3)
             scale <0.8,0.8,0.8>
             rotate <50,w4,0>
             translate y*1
         #end             
         #if(i>2)
             scale <0.7,0.7,0.7>
             rotate <40,w3,0>
             translate y*1
         #end             
         #if(i>1)
             scale <0.6,0.6,0.6>
             rotate <50,w2,0>
             translate y*1
         #end
         normal{granite 0.3 scallop_wave  scale 0.6}
         }
#if(i=6)#declare w6=w6+120;#end
#if(i=5)#declare w5=w5+120;#end
#if(i=4)#declare w4=w4+120;#end
#if(i=3)#declare w3=w3+120;#end
#if(i=2)#declare w2=w2+180;#end

#declare i=i-1;
#end


//////////////////////////////
#macro leaves()

#declare i=i+1;

#if (i<6)
    leaves()
    leaves()
#end

#if(i=6)sphere{<0,0,0>,0.8 pigment{bozo scale 0.1 color_map{[0.25 color rgb<0.5,0.6,0.4>][0.35 color rgbt 1]}}
         scale<3,1,3>scale 0.7 translate y*1
         #if(i>5)
            scale <0.5,1.5,0.5>
            rotate <60,ww6,0>
            translate y*1
         #end 
         #if(i>4)
            scale <0.8,1.0,0.8>
            rotate <60,ww5,0>
            translate y*1
         #end            
         #if(i>3)
             scale <0.8,0.8,0.8>
             rotate <50,ww4,0>
             translate y*1
         #end             
         #if(i>2)
             scale <0.7,0.7,0.7>
             rotate <40,ww3,0>
             translate y*1
         #end             
         #if(i>1)
             scale <0.6,0.6,0.6>
             rotate <50,ww2,0>
             translate y*1
         #end
         normal{spotted 0.5  scale 0.02}
         }
#end
         
#if(i=6)#declare ww6=ww6+120;leaves()#end
#if(i=5)#declare ww5=ww5+120;#end
#if(i=4)#declare ww4=ww4+120;#end
#if(i=3)#declare ww3=ww3+120;#end
#if(i=2)#declare ww2=ww2+180;#end

#declare i=i-1;
#end


#declare tree=
union
{
  blob
  {
    threshold 0.3
    tribe()
  }
  #declare i=0;
  leaves()
  scale 1.5
}
////////////////////////////////
////////////////////////////////

object{tree
translate<4, 0, 5>
rotate<0 + clock*700, 0  ,0 + clock*700>}