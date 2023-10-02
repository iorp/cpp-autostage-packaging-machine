//f = new Control.Window({Left:5,Top:5,Width:400,Text:"PanelWindow"});
//g = new Control.Mega2560({WindowState:1,Left:5,Top:5,Width:400,Text:"Mega"});

//pool.addControl(f);
//pool.addControl(g);


Control.Mega2560 Mega2560 {
// initial values can be set at class declaration
 var Top=14; 
 var Left=120; 
var Width=40; 
var Height=40; 
 var BackColor = "#FFFFFF";
constructor(Left = 10){
// also in the constructor
this.Left = Left; // Control.SetProps executes on instantiation and also on constructor as well in case it exists
}
}

a = new Mega2560(123);

//console.log(pool.controlType); 
 // add control 
pool.addControl(a); 
// Set a property
a.prop("Left",50); 
// Set several properties 
a.prop({Left:5,Top:5,Width:100,Height:100,Visible:true}); 
 