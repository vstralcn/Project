#include <iostream>
#include <vector>
#include <cmath>

// ������Ϸ�е�һ����λ��Ӣ�ۻ�С����
class Unit {
public:
    std::string name;
    int health;
    int attackDamage;
    double positionX;
    double positionY;

    Unit(std::string n, int hp, int ad, double x, double y) :
        name(n), health(hp), attackDamage(ad), positionX(x), positionY(y) {
    }

    // �򵥵��ƶ�����
    void move(double targetX, double targetY, double speed) {
        double distance = std::sqrt(std::pow(targetX - positionX, 2) + std::pow(targetY - positionY, 2));
        if (distance > 0) {
            double deltaX = (targetX - positionX) / distance;
            double deltaY = (targetY - positionY) / distance;
            positionX += deltaX * speed;
            positionY += deltaY * speed;
            std::cout << name << " �ƶ��� (" << positionX << ", " << positionY << ")" << std::endl;
        }
    }

    // �򵥵Ĺ�������
    void attack(Unit& target) {
        std::cout << name << " ���� " << target.name << ", ��� " << attackDamage << " ���˺���" << std::endl;
        target.health -= attackDamage;
        std::cout << target.name << " ʣ������ֵ: " << target.health << std::endl;
    }

    bool isAlive() const {
        return health > 0;
    }
};

int main() {
    // ��������Ӣ��
    Unit hero1("��ɪ", 1000, 50, 0.0, 0.0);
    Unit hero2("槼�", 800, 80, 5.0, 5.0);

    // Ӣ���ƶ�
    hero1.move(3.0, 3.0, 0.5);
    hero2.move(2.0, 2.0, 0.3);

    // Ӣ�ۻ��๥��
    while (hero1.isAlive() && hero2.isAlive()) {
        hero1.attack(hero2);
        if (!hero2.isAlive()) break;
        hero2.attack(hero1);
    }

    // ���ս�����
    if (hero1.isAlive()) {
        std::cout << hero1.name << " �����ʤ����" << std::endl;
    }
    else {
        std::cout << hero2.name << " �����ʤ����" << std::endl;
    }

    return 0;
}