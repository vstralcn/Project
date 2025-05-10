#include <iostream>
#include <vector>
#include <cmath>

// 代表游戏中的一个单位（英雄或小兵）
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

    // 简单的移动方法
    void move(double targetX, double targetY, double speed) {
        double distance = std::sqrt(std::pow(targetX - positionX, 2) + std::pow(targetY - positionY, 2));
        if (distance > 0) {
            double deltaX = (targetX - positionX) / distance;
            double deltaY = (targetY - positionY) / distance;
            positionX += deltaX * speed;
            positionY += deltaY * speed;
            std::cout << name << " 移动到 (" << positionX << ", " << positionY << ")" << std::endl;
        }
    }

    // 简单的攻击方法
    void attack(Unit& target) {
        std::cout << name << " 攻击 " << target.name << ", 造成 " << attackDamage << " 点伤害。" << std::endl;
        target.health -= attackDamage;
        std::cout << target.name << " 剩余生命值: " << target.health << std::endl;
    }

    bool isAlive() const {
        return health > 0;
    }
};

int main() {
    // 创建两个英雄
    Unit hero1("亚瑟", 1000, 50, 0.0, 0.0);
    Unit hero2("妲己", 800, 80, 5.0, 5.0);

    // 英雄移动
    hero1.move(3.0, 3.0, 0.5);
    hero2.move(2.0, 2.0, 0.3);

    // 英雄互相攻击
    while (hero1.isAlive() && hero2.isAlive()) {
        hero1.attack(hero2);
        if (!hero2.isAlive()) break;
        hero2.attack(hero1);
    }

    // 输出战斗结果
    if (hero1.isAlive()) {
        std::cout << hero1.name << " 获得了胜利！" << std::endl;
    }
    else {
        std::cout << hero2.name << " 获得了胜利！" << std::endl;
    }

    return 0;
}