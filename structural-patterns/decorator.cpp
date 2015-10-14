#include <iostream> 
#include <string>

using namespace std;

class Window  {
	public:
		virtual void draw() = 0;
		virtual string getDescription() = 0;
		virtual ~Window() {}
};

class SimpleWindow : public Window {
	public:
		void draw() {
		}
		string getDescription() {
			return "simple window\n";
		}
};

class WindowDecorator : public Window  {
	protected:
		Window *m_decoratedWindow; 

	public:
		WindowDecorator (Window *decoratedWindow): 
		m_decoratedWindow(decoratedWindow) {}
};

class VerticalScrollBarDecorator : public WindowDecorator {
	public:
		VerticalScrollBarDecorator (Window *decoratedWindow): 
		WindowDecorator(decoratedWindow) {}

		void draw() {
			drawVerticalScrollBar();
			m_decoratedWindow->draw();
		}

		string getDescription() {
			return m_decoratedWindow->getDescription() + "with vertical scrollbars\n";
		}

	private:
		void drawVerticalScrollBar() {
		}
};

class HorizontalScrollBarDecorator : public WindowDecorator {
	public:
		HorizontalScrollBarDecorator (Window *decoratedWindow): 
		WindowDecorator(decoratedWindow) {}

		void draw() {
			drawHorizontalScrollBar();
			m_decoratedWindow->draw();
		}

		string getDescription() {
			return m_decoratedWindow->getDescription() + "with horizontal scrollbars\n";
		}
	private:
		void drawHorizontalScrollBar() {
		}
};

int main()
{
	Window *simple = new SimpleWindow();
	cout << simple -> getDescription() << endl;

	Window *horiz = new HorizontalScrollBarDecorator ( new SimpleWindow());
	cout << horiz -> getDescription() << endl;

	Window *vert = new VerticalScrollBarDecorator ( new SimpleWindow());
	cout << vert -> getDescription() << endl;

	Window *decoratedWindow = new HorizontalScrollBarDecorator (
		new VerticalScrollBarDecorator(new SimpleWindow()));
	cout << decoratedWindow -> getDescription() << endl;

	return 0;
}