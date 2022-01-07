    # this is a demo python file
    class Person:
        def __init__(self, name) -> None:
            self.name = name

        def deal_name(self):
            print('ddedew')
            print('shit funct')
            print('%s is a shit person' % self.name)


    name = input("please input the damn name: ")
    demo = Person(name)
    demo.deal_name()
