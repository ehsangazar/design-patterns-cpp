#include <iostream>
using namespace std;

enum ErrorStates { ANALYZE=0, FIX, VERIFY, CLOSE };

class ErrorReport {
  private:  
    ErrorStates state;
      
  public:
    ErrorReport(ErrorStates state) {
        this->state = state;
    }
    ErrorStates GetState() {
        return state;
    }
    void SetState(ErrorStates state) {
        this->state = state;
    }
};

class Error {

  protected:
    ErrorStates state;
    Error* successor;
      
  public:
    Error(ErrorStates aState) { state = aState; }

    void SetSuccessor  (Error* error) {
        this->successor = error;
    }

    virtual void ProcessError(ErrorReport& report) = 0;
};

class AnalyzeError : public Error {

   public:
     AnalyzeError() : Error(ANALYZE) {};

     void ProcessError(ErrorReport& report) {
       if ( report.GetState() == ANALYZE ) {
           cout << "AnalyzeError::Handled the command to analyze the error ..." << endl;
       }else {
           cout << "AnalyzeError::Passing to my successor ..." << endl;
           successor->ProcessError(report);
       }
   }
};

class FixError : public Error {

  public:
    FixError() : Error(FIX) {};

    void ProcessError(ErrorReport& report) {
        if ( report.GetState() == FIX ) {
             cout << "FixError::Handled the command to fix the error ..." << endl;
        }
        else {
             cout << "FixError::Passing to my successor ..." << endl;
             successor->ProcessError(report);
        }
    }
};

class VerifyError : public Error {

  public:
    VerifyError() : Error(VERIFY) {};

    void ProcessError(ErrorReport& report) {
        if ( report.GetState() == VERIFY ) {
            cout << "VerifyError::Handled the command to verify the error ..." << endl;
        }
        else {
            cout << "VerifyError::Passing to my successor ..." << endl;
            successor->ProcessError(report);
        }
    }
};

class CloseError : public Error {

  public:
    CloseError() : Error(CLOSE) {};

    void ProcessError(ErrorReport& report) {
        if ( report.GetState() == CLOSE ) {
            cout << "CloseError::Handled the command to close the error ..." << endl;
        }
        else {
            cout << "VerifyError::No successor ... ignore" << endl;
            cout << "No action required ..." << endl;
        }
    }
};


int main() {
    // Create instances for processing objects
    AnalyzeError* analyzeError = new AnalyzeError();
    FixError* fixError = new FixError();
    VerifyError* verifyError = new VerifyError();
    CloseError* closeError = new CloseError();

    // Create the chain of responsibility
    analyzeError->SetSuccessor(fixError);
    fixError->SetSuccessor(verifyError);
    verifyError->SetSuccessor(closeError);

    // Issue command 1
    cout << "--------------- o/p for command 1 ----------------" << endl;
    ErrorReport* errorReport1 = new ErrorReport(ANALYZE);
    analyzeError->ProcessError(*errorReport1);

    // Issue command 2
    cout << "--------------- o/p for command 2 ----------------" << endl;
    ErrorReport* errorReport2 = new ErrorReport(CLOSE);
    analyzeError->ProcessError(*errorReport2);

    // Cleanup
    delete errorReport2;
    delete errorReport1;
    delete closeError;
    delete verifyError;
    delete fixError;
    delete analyzeError;
}