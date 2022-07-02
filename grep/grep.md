# تعرف علي أداه grep وكيف تستخدمها

### grep هي اداه سهله الفهم متوفره علي جمعيع انظمه تشغيل لينكس
### اداه grep هي اداه تستخدم للبحث عن البيانات النصيه وايجادها بسرعه ودقه

## نظره سريعه علي استخدام اداه ```grep``` 

#### في هذا المثال سنفترض ان لدينا ملف نصي باسم test_file.txt ويحتوي علي النص التالي 

![image](/grep/grep-example.png)

وبعدها سنقوم بتجربه grep علي هذا الملف

```bash
#bash
[ma@linux-distro ~]$ grep the test_file.txt 
```

```bash
#output
The weather is really good today
these are my favorite days in the week
```
>يمكنك النظر علي الصوره التاليه لايضاح ناتج عمليه البحث من خلال اداه ```grep```
![image](/grep/grep-first-ans.png)   
  من خلال المثال السابق يمكننا ان نستنتج ان الاداه تضع حاله الاحرف في الحسبان
  

### تثبيت الاداه علي نظام التشغيل 

##### اداه grep تاتي بشكل افتراضي مع معظم انظمه لينكس لكن اذا لم تكن مثبته  علي نظامك يمكنك تثتيتها من خلال الاوامر التاليه مع مراعاه نظام التشغيل الخاص بك

```bash   
#Debian/Ubuntu  
$ sudo apt-get install grep
```
```bash
#RHEL/CentOS/Fedora
$ sudo yum install grep
```
```bash
#Arch/Manjaro
$ sudo pacman -S grep 
```

## شرح الاداه

>**_ملاحظه:_** سوف نقوم بشرح الاداه علي [المثال السابق](#في-هذا-المثال-سنفترض-ان-لدينا-ملف-نصي-باسم-test_file.txt-ويحتوي-علي-النص-التالي 
)
* #### البحث عن كلمه واحده (ذات مقطع واحد)
```bash
[ma@linux-distro ~]$ grep the test_file.txt
The weather is really good today
these are my favorite days in the week
```

![image](/grep/grep-ans1.png)  

&emsp; grep ==> في المثال السابق هو اسم الاداه والذي يجب كتابته لاستخدامها

&emsp; the ==> تمثل النص الذي نحاول البحث عنه باستخدام grep

&emsp; test_file.txt ==> يمثل المستند النصي الذي نريد البحث في داخله





* #### البحث عن جمله (ذات اكثر من مقطع واحد)
```bash
[ma@linux-distro ~]$ grep "The weather" test_file.txt # يمكننا ان نلاحظ اننا كتبنا(The) بدلا من (the)
The weather is really good today
```
&emsp; "the weather" ==> هي جمله وبها مسافه ولذلك  يجب علينا استخدام علامتين التنصيص ( "" ) او علامه التنصيص الواحده ('')

![image](/grep/grep-ans2.png)




## شرح بعض الخيارات المفيده للاداه
#### 1. خيار ```-i``` يستخدم لجعل الاداه تهمل حاله الاحرف


من خلال الامثله السابقه يمكننا ملاحظه ان اداه ```grep``` تضح حاله الاحرف في الحسبان
**ولكن** يمكننا استخدام خيار من خيارات الاداه لجعلها تبحث بدون مراعاه حاله الاحرف
```bash
[ma@linux-distro ~]$ grep -i the test_file.txt # نلاحظ استخدام الخيار i قبل الكلمه او الجمله المراد البحث عنها
The weather is really good today 
these are my favorite days in the week
```
>**_ملاحظه:_** يتم كتابه الخيارات بعد اسم الاداه واضافه ```-``` ليكون الخيار بالشكل بهذا الشكل -i


![image](/grep/grep-ans3.png)




#### 2. خيار ```-n``` يستخدم لجلب رقم الاسطر التي وجدت بها الكلمه \ الكلمات المراده

##### من خلال الامثله السابقه كان من السهل علينا ادارك ان هذه الاداه تقوم بالبحث داخل الملف وتقوم باعلامنا اذا وجدت الكلمه دون ان تخبرنا بمكانها داخل هذا الملف لذلك اذا اردنا معرفه مكان القطعه النصيه المراده يمكننا ذلك عن طريق هذا الخيار

```bash
[ma@linux-distro ~]$ grep -n the test_file.txt
7:The weather is really good today
9:these are my favorite days in the week
```

![image](/grep/grep-ans4.png)

اذن السطر رقم 7 و السطر رقم 9 هما الاسطر التي يتواجد بها النمط النصي الذي قمنا بالبحث عنه


#### 3. خيار ```-w``` يستخدم للبحث فقط عن ما يطابق الكلمه \ الكلمات
##### من خلال هذا الاختيار يمكننا ان نجد نمط نصي بعينه فقط 
```bash
[ma@linux-distro ~]$ grep -w the test_file.txt
these are my favorite days in the week
```

![image](/grep/grep-ans5.png)

#### 4. خيار```-r``` يستخدم للبحث بداخل الملفات
اذا استخدمنا هذا الخيار فيمكن  ل ```grep``` البحث عن النمط المراد لكن بداخل المسار الذي سوف نحدده

> **_ملاحظه:_** بافتراض ان ملف test_file.txt موجود الان في المسار التالي **_Downloads/test-dir/test_file.txt_**

```bash
[ma@linux-distro ~]$ grep -r the Downloads/test-dir
Downloads/test-dir/test_file.txt:The weather is really good today
Downloads/test-dir/test_file.txt:these are my favorite days in the week
```

![image](/grep/grep-ans6.png)


### يمكنك الاجابه علي هذا السؤال لتتاكد من فهمك  للاداه و الخيارات التي تم شرحها

&emsp;بافتراض اننا الان بداخل مجلد مساره هو ``` Downloads/test-dir ```  يحتوي علي العديد من المستندات النصيه ونريد التالي
1. نريد ان نبحث بداخل هذا المجلد عن كلمه معينه بيعنها فقط وهي كلمه ```the```
2. نريد من الاداه ان تهمل حاله الاحرف
3. نريد من الاداه ان تظهر رقم الاسطر للكلمه المراد البحث عنها

<details> 
<summary style="color:blue; font-size:20px"> الاجابه </summary>

```bash
[ma@linux-distor ~]$ grep -iwnr the Downloads/test-dir 
```

</details>

و في النهايه يمكنك ان تعرف المزيد عن خيارات الاداه عن طريق كتابه الامر
```bash
[ma@linux-distor ~]$ grep --help
```


