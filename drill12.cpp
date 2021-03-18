//g++ first.cpp ../lib_files/Graph.cpp ../lib_files/Window.cpp ../lib_files/GUI.cpp ../lib_files/Simple_window.cpp -o first `fltk-config --ldflags --use-images`


#include "../lib_files/Simple_window.h"
#include "../lib_files/Graph.h"

int main() 
{

using namespace Graph_lib;

try{
	
	//7.2
	
	Point tl {100,100};
	Simple_window win (tl, 600, 400, "Krisz's Window");
	
	win.wait_for_button();
	
	//7.3
	
	Axis xa {Axis::x, Point{10,200}, 300, 10, "X tengely"};
	
	win.attach(xa);
	win.set_label("Krisz's Window 2");
	win.wait_for_button();
	
	Axis ya {Axis::y, Point{10,200}, 300, 10, "Y tengely"};
	
	ya.set_color(Color::red);
	ya.label.set_color(Color::green);
	win.attach(ya);
	win.set_label("Krisz's Window 3");
	win.wait_for_button();
	
	//7.4
	
	Function sine {sin,0,100,Point{30,200},2000,50,50};
	
	win.attach(sine);
	win.set_label("Krisz's Window 4");
	win.wait_for_button();
	
	
	//7.5
	
	sine.set_color(Color::yellow);
	
	Polygon haromszog;
	
	haromszog.add(Point{100,100});
	haromszog.add(Point{50,200});
	haromszog.add(Point{150,200});
	
	haromszog.set_color(Color::cyan);
	haromszog.set_style(Line_style::dash);
	win.attach(haromszog);
	win.set_label("Krisz's Window 5");
	win.wait_for_button();
	
	//7.6 & 7.6.1
	
	Rectangle r {Point{100,100},100,50};
	
	win.attach(r);
	win.set_label("Krisz's Window 6");
	win.wait_for_button();
	
	Closed_polyline notrect;
	notrect.add(Point{300,100});
	notrect.add(Point{400,100});
	notrect.add(Point{300,150});
	notrect.add(Point{400,150});
	
	win.attach(notrect);
	win.set_label("Krisz's Window 6.1");
	win.wait_for_button();
	
	//7.7
	
	r.set_fill_color(Color::white);
	haromszog.set_style(Line_style(Line_style::dash,3));
	notrect.set_style(Line_style(Line_style::dash,3));
	notrect.set_fill_color(Color::black);
	win.set_label("Krisz's Window 7");
	win.wait_for_button();
	
	//7.8
	
	Text t {Point{100,100}, "Hi I'm Krisz"};
	
	win.attach(t);
	win.set_label("Krisz's Window 8");
	win.wait_for_button();
	

	
	t.set_font(Font::times_bold);
	t.set_font_size(18);
	win.set_label("Krisz's Window 9");
	win.wait_for_button();
	
	//7.9
	
	Image pic {Point{100,100}, "soccer.jpg"};
	win.attach(pic);
	win.set_label("Krisz's Window 10");
	win.wait_for_button();
	
	pic.move(50,50);
	win.set_label("Krisz's Window 11");
	win.wait_for_button();
	
	//7.10
	
	Circle c {Point{60,60},20};
	Ellipse e {Point{60,60},30,10};
	e.set_color(Color::purple);
	Mark m {Point{60,60},'x'};
	
	ostringstream szov;
	szov << "Kepernyo merete: " << x_max() << "*" << y_max()
		<<"; Ablak merete: " << win.x_max() << "*" << win.y_max();
	Text meretek {Point{20,10}, szov.str()};
	
	Image biliard {Point{400,100}, "biliard.gif"};
	biliard.set_mask(Point{10,10},250,150);
	win.attach(c);
	win.attach(m);
	win.attach(e);
	
	win.attach(meretek);
	win.attach(biliard);
	win.set_label("Krisz's Window 12");
	win.wait_for_button();
	
}
	
catch(exception& e){
cerr << "exception: " << e.what() << '\n';
return 1;
}
catch(...){
cerr << "Valami hiba tortent!" << '\n';
return 2;
}
}
