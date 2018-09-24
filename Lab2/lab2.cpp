#include <iostream>

using namespace std;

class Cat {
 int lives; // Cats have 9 lives

  public:
    // Construct a Cat with the number of lives
    Cat(int startLives) : lives{startLives} {
      // nothing else to do
    }

    void reportLives(){
      cout << "This cat has " << lives << " lives remaining!" << endl;
    }

    void loseLife(){
      lives = lives - 1;
    }
};

int main() {
 Cat mittens(9);
 mittens.reportLives();
 mittens.loseLife();
 mittens.reportLives();

 return 0;
}
