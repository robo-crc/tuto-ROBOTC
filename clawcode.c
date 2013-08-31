/***
 *
 * This document is intended to provide a basic introduction to C# “grammar/ syntax”
 * The chips bios and registry are all set up with easyC automatically.
 *
 */

// Declaring memory locations (1byte) 8 bits (0 - 255) to store data:
int c1;
int c2;
int c3;
int c4;
int latch1;
int latch2;
int latch3;
int latch4;
int rc1x5;
int rc1x6;

// Setting up the 4RC channels and associating controls to outputs for 2 driving and 2 analog motors on the two thumb controls.
OIToPWM ( 1 , 1 , 1 , 0 ) ;
OIToPWM ( 1 , 2 , 2 , 0 ) ;
OIToPWM ( 1 , 3 , 3 , 0 ) ;
OIToPWM ( 1 , 4 , 4 , 0 ) ;
rc1x5 = GetRxInput ( 1 , 5 );
rc1x6 = GetRxInput ( 1 , 6 );
latch1=0;
latch2=0;
latch3=0;
latch4=0;

//// claw 1, declaring the state of the corresponding claw
if((rc1x5 > 127)&&(latch1==0))
{
    c1++;
    latch1=1;
}
if((rc1x5>126)&&(rc1x5<128)&&(latch1==1))
{
    latch1=0;
}
if(c1>4)
{
    c1=1;
}
if(c1==1)
{
    SetPWM ( 5 , 255 );
}
if(c1=2)
{
    SetPWM ( 5 , 127 );
}
if(c1==3)
{
    SetPWM ( 5 , 0 );
}
if(c1==4)
{
    SetPWM ( 5 , 127 );

///claw 2///
    if((rc1x5 < 127)&&(latch2==0))
    {
        c2++;
        latch2=1;
    }
    if((rc1x5>126)&&(rc1x5<128)&&(latch2==1))
    {
        latch2=0;
    }
    if(c2>4)
    {
        c2=1;
    }
    if(c2==1)
    {
        SetPWM ( 6 , 255 );
    }
    if(c2=2)
    {
        SetPWM ( 6 , 127 );
    }
    if(c2==3)
    {
        SetPWM ( 6 , 0 );
    }
    if(c2==4)
    {
        SetPWM ( 6 , 127 );
    }

//claw 3///
    if((rc1x6 > 127)&&(latch3==0))
    {
        c3++;
        latch3=1;
    }
    if((rc1x6>126)&&(rc1x6<128)&&(latch3==1))
    {
        latch3=0;
    }
    if(c3>4)
    {
        c3=1;
    }
    if(c3==1)
    {
        SetPWM ( 7 , 255 );
    }
    if(c3=2)
    {
        SetPWM ( 7 , 127 );
    }
    if(c3==3)
    {
        SetPWM ( 7 , 0 );
    }
    if(c3==4)
    {
        SetPWM ( 7 , 127 );
    }

//claw 4///
    if((rc1x6 < 127)&&(latch4==0))
    {
        c4++;
        latch4=1;
    }
    if((rc1x6>126)&&(rc1x6<128)&&(latch4==1))
    {
        latch4=0;
    }
    if(c4>4)
    {
        c4=1;
    }
    if(c4==1)
    {
        SetPWM ( 8 , 255 );
    }
    if(c4=2)
    {
        SetPWM ( 8 , 127 );
    }
    if(c4==3)
    {
        SetPWM ( 8 , 0 );
    }
    if(c4==4)
    {
        SetPWM ( 8 , 127 );
    }

// On the RC controller there are 4 analog (1,2,3,4) channels and 2 digital(5,6) channels
// Analog channels use numerical values between 0 and 255
// Digital inputs only register 0 or 255
// Each claw has 4 states that it rotates through
// Stop1, clockwise, stop2, counter clockwise
// Each claw has a C# value which is incremented whenever it detects a certain input from the one of the four buttons.
// Buttons within the same rc channel must be pressed independently.

    int rx2ch5;
    int upLimit;
    int downLimit;
    rx2ch5 = GetRxInput ( 2 , 5 ) ; //Get Transmitter 2 , Channel 5
    upLimit = GetDigitalInput ( 5 ) ; // Get Limit Switch In port 5
    downLimit = GetDigitalInput ( 6 ) ; // Get Limit Switch In port 6
    if ( rx2ch5 > 127 ) // Top CH5 Button Hit
    {
        SetMotor ( 6 , 255 ) ; // Run the motor Full Speed Clockwise
    }
    if ( rx2ch5 < 127 ) // Buttom CH5 Button Hit
    {
        SetMotor ( 6 , 0 ) ; // Run the motor Full Speed Counter Clockwise
    }
    if ( upLimit == 0 || downLimit == 0 ) // Top Limit OR Bottom Limit Hit
    {
        SetMotor ( 6 , 127 ) ; // Stop the Motor
    }