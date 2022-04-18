#include <iostream>
#include <string>
using namespace std;
//1. Создать программу, которая считывает целое число типа int. И поставить «защиту от
//дурака»: если пользователь вводит что-то кроме одного целочисленного значения, нужно
//вывести сообщение об ошибке и предложить ввести число еще раз. Пример
//неправильных введенных строк:
//rbtrb
//nj34njkn
//1n

template<class T>
T input_user(const char* promt){
    T a; cout << promt; cin >> a;
    while (cin.fail() || cin.get() != '\n'){
        cin.clear();
        cin.ignore(9999, '\n');
        cin.sync();
        cout << "Error!\n\n" << promt; std::cin >> a;
    }
    return a;
}

//2. Создать собственный манипулятор endll для стандартного потока вывода, который
//выводит два перевода строки и сбрасывает буфер.

template< class CharT, class Traits >
std::basic_ostream<CharT, Traits>& endll(std::basic_ostream<CharT, Traits>& os)
{
    os.put(os.widen('\n'));
    os.put(os.widen('\n'));
    os.flush();

    return os;
}
//3 Реализовать класс Player, который наследует от класса GenericPlayer. У этого класса
//будет 4 метода:
//• virtual bool IsHitting() const - реализация чисто виртуальной функции базового класса. Метод
//спрашивает у пользователя, нужна ли ему еще одна карта и возвращает ответ пользователя в виде
//true или false.
//• void Win() const- выводит на экран имя игрока и сообщение, что он выиграл.
//• void Lose() const - выводит на экран имя игрока и сообщение, что он проиграл.
//• void Push() const - выводит на экран имя игрока и сообщение, что он сыграл вничью.
// (я не думаю что имеет смыс вставлять сюда огромное количество кода написанного за все уроки до этого 
// по этому я вставил сюда только то что относится к заданию на этом уроке)

class Player : public GenericPlayer{
public:
    Player(const string& name = "");
    virtual ~Player();
    bool IsHitting() const {
        cout << m_Name;
        char response;
        cin >> response;
        return (response == 'y' || response == 'Y');
    }
    void Win() const {
        cout << m_Name << " wins.\n";
    }
    void Lose() const {
        cout << m_Name << " loses.\n";
    }
    void Push() const {
        cout << m_Name << " pushes.\n";
    }

    //4 Реализовать класс House, который представляет дилера. Этот класс наследует от
    //класса GenericPlayer. У него есть 2 метода:
    //• virtual bool IsHitting() const - метод указывает, нужна ли дилеру еще одна карта. Если у дилера не
    //больше 16 очков, то он берет еще одну карту.  
    //• void FlipFirstCard() - метод переворачивает первую карту дилера.

    class House : public GenericPlayer {
    public:
        House(const string& name = "House");
        virtual ~House();
        bool IsHitting() const {
            return (GetTotal() <= 16);
        }
        void FlipFirstCard() {
            if (!(m_Cards.empty())) {
                m_Cards[0]->Flip();
            }
            else {
                cout << "No card to flip!\n";
            }
        }
    };
};

//5 Написать перегрузку оператора вывода для класса Card. Если карта перевернута рубашкой
//вверх (мы ее не видим), вывести ХХ, если мы ее видим, вывести масть и номинал карты
//Также для класса GenericPlayer написать перегрузку оператора вывода, который должен
//отображать имя игрока и его карты, а также общую сумму очков его карт.









int main(){
    cout << input_user<int>("Enter an integer: ");

    //+++----------------------------------------
    std::cout << "A" << endll;
    std::cout << "B";
    return 0;
}


