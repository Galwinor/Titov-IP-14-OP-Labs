def inpt(File):       # Ввід тексту 
    File1 = open(File, "w")
    s = ''
    flag = True
    while flag:
        s = input()
        if s.find(chr(20)) != -1:
            flag = False
            s = s.replace(chr(20), '')
        if s != '':
            File1.write(s + "\n")
    File1.close()

def outpt(File):  # Вивід файла
    File1 = open(File, "r")
    s = File1.read()
    print(s)
    File1.close()
    
def newFile(FileOne, FileTwo, n):  # Запис слів у другий файл
    k = 0                                   
    str = " "                   
    st = ""        
    File1 = open(FileOne, "r")   
    str = File1.readline()
    str = str.replace("\n", "")
    while str != "":               
        while str.find(" ") != -1:
            word = str[0:str.find(" ")]   
            str = str.replace(word + ' ', "", 1)      
            k = count(FileOne, word)              
            File2 = open(FileTwo, "r")  
            st = File2.readline()                 
            File2.close();
            if k < n and st.find(" " + word + " ") == -1 and st[0: st.find(" ")] != word: 
                File2 = open(FileTwo, "a")
                File2.write(word + " ")            
                File2.close()
        if str.find(chr(13)) != -1:
            word = str[0: str.find(chr(13))]
        else:
            word = str
        k = count(FileOne, word);   
        File2 = open(FileTwo, "r")  
        st = File2.readline()
        str = st.replace("\n", "")
        File2.close();
        if k < n and st.find(" " + word + " ") == -1 and st[0: st.find(" ")] != word:
            File2 = open(FileTwo, "a")
            File2.write(word + " ")            
            File2.close()
        str = File1.readline()
        str = str.replace("\n", "")
    File1.close();

def count(FileOne, word):  # Підрахунок кількості повторень слова
    File1 = open(FileOne, "r")        # Відкриття файла для читання
    k = 0   # Кількість повторень кожного слова
    str = File1.readline()
    str = str.replace("\n", "")
    while str != "":
        while str.find(" ") != -1:
            word1 = str[0: str.find(" ")]  # Запис першого слово
            str = str.replace(word1 + " ", "", 1);       # Видалення першого слова рядка
            if word1 == word:    # Порівняння слів
                k += 1   # Кількість слів + 1
        if str.find(chr(13)) != -1:
            word1 = str[0: str.find(chr(13))]
        else:
            word1 = str
        if word1 == word:
            k += 1
        str = File1.readline()
        str = str.replace("\n", "")
    File1.close();
    return k

def sort(FileTwo):  # Сортування бульбашкою
    k = NumWords(FileTwo) # Кількість слів в рядку
    l = 0                 # індекс масиву
    File2 = open(FileTwo, "r")
    st = ["" for i in range (k)] # Масив слів
    str = File2.readline()
    str = str.replace("\n", "")
    File2.close()
    while str.find(" ") != -1:   # Запис слів з рядка у масив
        word = str[0: str.find(" ")] # Запис першого слова рядка
        str = str.replace(word + " ", "", 1)     # Видалення першого слова рядка
        st[l] = word
        l += 1  # Збільшення індекса
    st[k - 1] = str #Запис останнього слова рядка
    for i in range(k):
        for j in range(k - i - 1):
            if len(st[j]) < len(st[j + 1]):  # Порівняння довжини слів
                el = st[j] # Зберыгання значення елементу масива
                st[j] = st[j + 1] # Заміна значення елементів
                st[j + 1] = el    # Заміна значення елементів
    File2 = open(FileTwo, "w")
    for i in range(k):
        File2.write(st[i] + " ")
    File2.close()

def NumWords(FileTwo): # Кількість слів у рядку
    k = 0  # Кількість слів у рядку
    File = open(FileTwo, "r")# Відкриття файла для читання
    st = File.readline()
    st = st.replace("\n", "")
    for i in range(len(st)):
        if st[i] == ' ':
            k+=1    
    File.close();
    return k + 1 

def MoreInpt(FileOne): # Дописування у функцію
    File = open(FileOne, "a")  # Відкриття файла для запису
    flag = True            # Наявність символа кінця файла
    endf = chr(20)              # Ctrl + T - символ завершення файла
    while flag:               # Виконується поки не знайшло символ завершення файла
        s = input()
        if s.find(endf) != -1:    # Пошук у рядку Ctrl + T
            flag = False
            s = s.replace(endf, "");          # Видалення символа
        if s != "":           # Запис рядку у файл, якщо рядок не пустий
            File.write(s + "\n")
    File.close()

def inputPlus(FileOne, FileTwo, n): # Збірка функцій
    File = open(FileTwo, "w")
    File.close();
    print("First File: ")
    outpt(FileOne)
    newFile(FileOne, FileTwo, n);
    print("\nSecondFile unsorted: ")
    outpt(FileTwo);
    sort(FileTwo);
    print("\nSecondFile sorted: ")
    outpt(FileTwo);
