import random
from typing import Type


class Player:
    def __init__(self, index: int):
        self.index = index  # 플레이어의 고유 인덱스
        self.hp = 50  # 초기 체력
        self.ad = 10  # 초기 공격력
        self.ap = 5  # 초기 마법력

    # 사용자가 입력한 점수에 따라 플레이어의 스테이터스 포인트를 설정하는 메서드
    def status_set(self, point: int):
        print("------------------------------------------------------------------------------")
        print(f"{point}만큼의 스테이터스를 추가합니다. 체력, 공격력, 마법력 순으로 입력하세요\n(1 포인트 당 체력 = 3, 공격력 = 1, 마법력 = 1 증가)\n")
        print("플레이어의 기본 스탯은 체력: 50, 공격력: 10, 마법력: 5입니다.\n")

        while True:
            try:
                hp_point, ad_point, ap_point = map(int, input("체력, 공격력, 마법력 순으로 입력: ").split())

                if hp_point + ad_point + ap_point == point:
                    self.hp += hp_point * 3
                    self.ad += ad_point
                    self.ap += ap_point
                    print(f"변경된 스탯 - 체력: {self.hp}, 공격력: {self.ad}, 마법력: {self.ap}\n")
                    break
                else:
                    print(f"포인트의 합이 {point}와 일치하지 않습니다. 다시 입력해주세요.")
            except:
                print("hp, ad, ap는 정수로 입력해야 합니다. 다시 입력해주세요.")
                continue

    # 플레이어 hp 감소
    def decrease_hp(self, damage: int):
        self.hp = max(self.hp - damage, 0)

    # 플레이어 1번
    def check_status(self, enemy):
        # 플레이어와 적의 현재 상태를 출력합니다.
        print(f"현재 유저: 체력 {self.hp}, 공격력 {self.ad}, 마법력 {self.ap}")
        print(f"적: 체력 {enemy.hp}, 공격력 {enemy.ad}, 방어력 {enemy.ad_defence}, 마법방어력 {enemy.ap_defence}\n")
        # 적에게 일반 공격을 가합니다.
        damage = self.ad - enemy.ad_defence
        damage = max(damage, 0)  # 데미지는 0 이상 음수 예방
        enemy.decrease_hp(damage)
        print(f"일반 공격으로 {damage}의 데미지를 주었습니다.\n")

    # 플레이어 2번
    def basic_attack(self, enemy: Type["Enemy"]):
        crit_chance = random.randint(1, 10)
        if crit_chance <= 2:
            damage = (self.ad - enemy.ad_defence) * 2
            damage = max(damage, 0)  # 데미지는 0 이상이어야 합니다.
            print(f"치명타가 적용되어 {damage}의 데미지를 주었습니다.")
        else:
            damage = self.ad - enemy.ad_defence
            damage = max(damage, 0)  # 데미지는 0 이상이어야 합니다.
            print(f"일반 공격으로 {damage}의 데미지를 주었습니다.")
        enemy.decrease_hp(damage)

    # 플레이어 3번
    def magic_attack(self, enemy: Type["Enemy"]):
        damage = self.ap * 2 - enemy.ap_defence
        damage = max(damage, 0)
        enemy.decrease_hp(damage)
        print(f"마법 공격으로 {damage}의 데미지를 주었습니다.\n")

    # 플레이어 4번
    def heal_self(self):
        heal_amount = random.randint(5, 10)
        self.hp += heal_amount
        print(f"체력을 {heal_amount}만큼 회복합니다. 현재 hp는 {self.hp}입니다.\n")

    def attack(self, enemy: Type["Enemy"]):
        # 사용자로부터 input key를 받아옵니다.
        while True:
            try:
                print("------------------------------------------------------------------------------")
                print(
                    f"{self.index + 1}번 플레이어의 차례입니다. 행동을 선택하세요. (1: 스테이터스 확인 + 일반 공격, 2: 기본 공격, 3: 마법 공격, 4: 체력 회복, exit: 종료)\n")
                input_key = input()
                input_key = int(input_key)
                if input_key < 1 or input_key > 4:
                    print("1~4 사이의 정수를 입력해주세요.")
                    continue
                break
            except ValueError:
                print("잘못된 입력입니다. 숫자를 입력해주세요.")

        if input_key == 1:
            self.check_status(enemy)
        elif input_key == 2:
            self.basic_attack(enemy)
        elif input_key == 3:
            self.magic_attack(enemy)
        elif input_key == 4:
            self.heal_self()


class Enemy:
    # 적의 속성 초기화 작업
    def __init__(self, list_num: int):
        self.max_hp = 100 * list_num
        self.hp = 100 * list_num
        self.ad = 25
        self.ad_defence = 7
        self.ap_defence = 7

    # 적의 체력 감소
    def decrease_hp(self, damage: int):
        self.hp = max(self.hp - damage, 0)

    # 적의 기본 공격
    def basic_attack(self, player: Type[Player]):
        # 공격 대상 플레이어의 체력을 적의 공격력만큼 감소시키고, 공격 받은 플레이어의 남은 체력을 출력합니다.
        damage = self.ad
        player.decrease_hp(damage)
        print(f"{player.index + 1}번 유저에게 {damage}의 데미지. 현재 남은 체력은 {player.hp}입니다.\n")

    # 적의 체력 회복
    def heal_self(self):
        healing_amount = 7
        if self.max_hp < (self.hp + healing_amount):
            self.hp = self.max_hp
            print(f"적의 회복으로 현재 적의 체력은 {self.hp}입니다.\n")
        else:
            self.hp += healing_amount
            print(f"적의 회복으로 현재 적의 체력은 {self.hp}입니다.\n")

    # 적의 공격 타임
    def attack(self, player: Type[Player]):
        print("------------------------------------------------------------------------------")
        print("적의 차례입니다.\n")
        enemy_action = random.randint(1, 10)
        if enemy_action == 1:
            print("적은 섣불리 움직이지 못하고 있습니다.\n")
        elif 2 <= enemy_action <= 8:
            self.basic_attack(player)
        else:
            self.heal_self()
        return enemy_action


class Game:
    def __init__(self):
        self.status_point = 13
        self.player_list = []

    def set_players(self):
        list_num = []
        while True:
            try:
                list_num = int(input("플레이어 인원을 정하세요: "))
                if list_num <= 0:
                    print("플레이어 수는 1명 이상이어야 합니다.")
                    continue
                break
            except ValueError:
                print("잘못된 입력입니다. 숫자를 입력해주세요.")
                continue

        for i in range(list_num):
            player = Player(i)
            self.player_list.append(player)
            player.status_set(self.status_point)
        return list_num

    # 체력 0 이하인 플레이어 제거
    def turn_check(self):
        self.player_list = [player for player in self.player_list if player.hp > 0]

    # player_list에서 무작위로 플레이어를 선택하여 반환합니다.
    def get_random_target_player(self):
        return random.choice(self.player_list)

    def game(self):
        list_num = self.set_players()
        enemy = Enemy(list_num)

        while True:
            for player in self.player_list:
                player.attack(enemy)
                if enemy.hp <= 0:
                    print("축하합니다. 승리하였습니다!")
                    return

            self.turn_check()
            if not self.player_list:
                print("아쉽지만 패배하셨습니다.")
                return

            target_player = self.get_random_target_player()
            enemy.attack(target_player)
            if target_player.hp <= 0:
                self.turn_check()
                if not self.player_list:
                    print("아쉽지만 패배하셨습니다.")
                    return


if __name__ == "__main__":
    Game().game()
