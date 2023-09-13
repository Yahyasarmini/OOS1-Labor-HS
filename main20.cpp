
#include <iostream>
#include<string>
using namespace std;

class AuthenticationResult{
    private:
     bool _authenticated;
     string _username;
    public:
    AuthenticationResult(bool authenticated, string username ="unauthenticated_user"): _authenticated(authenticated),_username(username){};
    void set_auth(bool auth){
         _authenticated = auth;
    }
    bool get_auth(){
        return _authenticated;
    }
    void set_Username(string name){
        _username = name;
    }
    string get_Username(){
        return _username;
    }
    
    };
    
    class IAuthenticationMethod{
        public :
         virtual AuthenticationResult authenticate() = 0;

    };
    
   class Client{
    private:
    IAuthenticationMethod * _authentication_method;
    AuthenticationResult Result = AuthenticationResult(false, "unauthenticated_user");
    public :
    void set_authentication_method(IAuthenticationMethod * authentication_method){
        _authentication_method = authentication_method;
    }
    void execute(){
        Result = _authentication_method->authenticate();
        if (Result.get_auth())
        {
            cout << "Das Programm wird ausgeführt für " << Result.get_Username() << "." << endl;
        }
        else{
            cout << "Das Programm konnte nicht ausgeführt werden." << endl; 
        }
        
    }
   };

class MockAuth : public IAuthenticationMethod {
public:
    AuthenticationResult authenticate() override {
        return AuthenticationResult(true, "Default");
    }
};
class UsernamePassword : public IAuthenticationMethod{
    AuthenticationResult authenticate() override {
    string username;
    string password;
    cout << "Username: " << endl;
    cin >> username;
    cout << "Password: " << endl;
    cin >> password;
    if ( username == password ){
        return AuthenticationResult(true, username);
    }else{
        return AuthenticationResult(false, username);
    }
    }
};

class Certificate : public IAuthenticationMethod{
    public :
    AuthenticationResult authenticate(){
        string Zertifikatsaussteller;
        cout << "Zertifikatsaussteller: " << endl;
        cin >> Zertifikatsaussteller; 
        if (Zertifikatsaussteller == "hs-esslingen")
        {
            return AuthenticationResult(true,"certificate.owner");
        }
        else
        {
            return AuthenticationResult(false);
        }
        
    }
};
int main(int argc, char* argv[]) {
    Client client;

    cout << "Authentifizierung über die Authentifizierungsmethode Mock Authentication" << endl;
    IAuthenticationMethod* mock_authentication = new MockAuth();
    client.set_authentication_method(mock_authentication);
    client.execute();

    cout << "Authentifizierung über die Authentifizierungsmethode Username Password" << endl;
    IAuthenticationMethod* username_password = new UsernamePassword();
    client.set_authentication_method(username_password);
    client.execute();

    cout << "Authentifizierung über die Authentifizierungsmethode Zertifikat" << endl;
    IAuthenticationMethod* certificate = new Certificate();
    client.set_authentication_method(certificate);
    client.execute();
    return 0;
}

