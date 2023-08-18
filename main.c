#include <stdio.h>
#include <stdlib.h>
int main() {

      int z ;
      printf(" ادخل عدد الأفراد (المرضى ) لديك ");
      scanf("%d",&z);
     int maxPatients = z; // تحديد عدد الحالات القصوى
    float taille[maxPatients], poids[maxPatients];
    int nombrePatients = 0;

    // A. قم بتسجيل طول كل مريض وتخزينه في جدول
    printf("إدخال طول المرضى (بالأمتار). لإيقاف الإدخال، أدخل قيمة <= 0:\n");
    for (int i = 0; i < maxPatients; ++i) {
        printf("المريض %d: ", i + 1);
        scanf("%f", &taille[i]);
        if (taille[i] <= 0) {
            break;
        }
        nombrePatients++;
    }

    // B. عرض إجمالي عدد المرضى
    printf("عدد المرضى الإجمالي: %d\n", nombrePatients);

    // C. قم بتسجيل وزن كل مريض وتخزينه في جدول
    for (int i = 0; i < nombrePatients; ++i) {
        printf("المريض %d - إدخال وزنه (بالكيلوجرام): ", i + 1);
        scanf("%f", &poids[i]);
    }

    // D. حساب وعرض المتوسط ​​للطول والوزن
    float sommeTaille = 0, sommePoids = 0;
    for (int i = 0; i < nombrePatients; ++i) {
        sommeTaille += taille[i];
        sommePoids += poids[i];
    }
    float moyenneTaille = sommeTaille / nombrePatients;
    float moyennePoids = sommePoids / nombrePatients;
    printf("المتوسط ​​للطول: %.2f متر\n", moyenneTaille);
    printf("المتوسط ​​للوزن: %.2f كجم\n", moyennePoids);

    // E. حساب وعرض مؤشر كتلة الجسم (IMC) لكل مريض
    printf("مؤشر كتلة الجسم (IMC) لكل مريض:\n");
    for (int i = 0; i < nombrePatients; ++i) {
        float imc = poids[i] / (taille[i] * taille[i]);
        printf("المريض %d - IMC: %.2f - الحالة: ", i + 1, imc);
        if (imc < 18.5) {
            printf("غير كافٍ\n");
        } else if (imc > 25) {
            printf("زائد\n");
        } else {
            printf("طبيعي\n");
        }
    }

    return 0;
}
