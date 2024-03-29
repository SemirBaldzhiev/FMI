# FN: 8MI0700024
# Семир Балджиев
# Информационни системи


### 1
observed <- c(267, 91, 103, 39)  # 39 прдставлява броят на бадемите (500 - 267 - 91 - 103)

expected <- c(5, 2, 2, 1) / sum(c(5, 2, 2, 1))


# Използвам chisq test
# Хипотези:
# H0: Машината смесва ядките в желаното съотношение.
# H1: Машината не смесва ядките в желаното съотношение.
result <- chisq.test(observed, p = expected)
# p-value = 0.2144 > 0.05 нямаме основание да отхвърлим H0 => Машината смесва ядките в желаното съотношение.

x <- seq(0, 20, length.out = 1000)
y <- dchisq(x, result$parameter)
plot(x, y, type = "l", xlab = "Chi-squared value", ylab = "Density", main = "Density Distribution")
abline(v = result$statistic, col = "blue", lwd = 2)  
abline(v = result$parameter, col = "red", lwd = 2, lty = 2)
legend("topright", legend = c("Empirical Region", "Critical Region"),
       col = c("blue", "red"), lty = c(1, 2), lwd = c(2, 2))

print(result)



### 2

# Хипотези:
# H0: Процентът на дефектни елементи при използване на робот е 
# същият или по-голям от процента на дефектни елементи при сглобяване от човек.
# H1: Процентът на дефектни елементи при използване на робот 
# е по-малък от процента на дефектни елементи при сглобяване от човек.

n_robot <- 500  # Брой елементи, сглобени от робот
defects_robot <- 15  # Брой дефектни елементи при използване на робот
p_human <- 0.035  # Процент на дефектни елементи при сглобяване от човек
alpha <- 0.04  # Ниво на значимост

# Изчисляване на статистиката и критичната стойност
p_robot <- defects_robot / n_robot  # Процент на дефектни елементи при използване на робот
p_upper <- p_human  # Горна граница за теста на пропорции
n_upper <- n_robot  # Общ брой елементи за горната граница
z <- (p_robot - p_upper) / sqrt((p_upper * (1 - p_upper)) / n_upper)
z_critical <- qnorm(1 - alpha)

# Проверка на нулевата хипотеза
if (z < z_critical) {
  print("Отхвърляме нулевата хипотеза.")
  print("Има статистически значими доказателства, че
        процентът дефектни елементи при използване на робот
        е по-малък от процента при сглобяване от човек.")
} else {
  print("Не отхвърляме нулевата хипотеза.")
  print("Няма статистически значими доказателства, 
        че процентът дефектни елементи при използване 
        на робот е по-малък от процента при сглобяване от човек.")
}


### 3
x_3 = c(30208.61, 30031.48, 31369.72, 30423.30, 28508.69, 30909.14, 29951.86,
      29651.07, 30092.92, 28934.14, 29548.45, 28838.97, 30333.31, 30535.98,
      31070.35, 31016.58, 28130.97, 29661.08, 30401.63, 31377.73, 29469.36,
      30411.83, 29530.51, 29803.23, 29491.12, 30340.85, 30239.38, 29328.12,
      30892.51, 31095.85, 30180.62, 28347.43, 30056.37, 30103.87, 29520.86,
      30201.51, 32292.90, 30325.08, 30318.04, 30460.16, 30902.91, 29832.22,
      31682.61, 30667.66, 31644.24, 30333.04, 29248.99, 29039.49)
y_3 = c(30138.48, 28128.17, 28457.52, 30869.64, 28350.69, 29833.84, 29906.35,
      27893.71, 30651.77, 29306.76, 29694.77, 28871.06, 29111.43, 29633.97,
      27248.59, 29677.19, 27304.51, 28393.82, 29049.14, 28471.64, 29624.78,
      30197.94, 29329.87, 28435.96, 29566.51, 28194.91, 29506.66, 28668.88,
      32377.36, 28764.72, 27153.31, 29129.34, 28193.12, 28103.39, 27355.46,
      29829.73, 30631.48, 29152.45, 30994.12, 30083.63, 29757.24, 28243.70,
      29023.39, 28290.52, 28230.68, 29105.40, 28693.04, 29281.10)

# Проверка за нормално разпределение
shapiro.test(x_3)
shapiro.test(y_3)

# Използвам t test
# Хипотези:
# H0: Средното изминато разстояние до износване е еднакво за гумите от марка X и марка Y.
# H1: Средното изминато разстояние до износване е различно за гумите от марка X и марка Y.
#
result_3 <- t.test(x_3, y_3, alternative = "greater", var.equal = TRUE, conf.level = 0.96)
# p-value < 0.04 => отхвърляме H0 и приемаме алтернативната хипотеза (H1)


critical_t <- qt(0.96, df = length(x_3) + length(y_3) - 2)

density_x <- density(x_3)
density_y <- density(y_3)

plot(density_x, xlim = c(min(density_x$x, density_y$x), max(density_x$x, density_y$x)),
     main = "Density Distribution of Brand X and Brand Y",
     xlab = "Distance to Wear", ylab = "Density", lwd = 2)
lines(density_y, lwd = 2, col = "green")
abline(v = result_3$estimate, lwd = 2, col = "blue", lty = 2)
abline(v = result_3$estimate + critical_t * result_3$stderr, lwd = 2, col = "red", lty = 2)
legend("topright", legend = c("Brand X", "Brand Y", "Critical Region", "Estimated Mean"),
       lwd = c(2, 2, 2, 2), col = c("black", "green", "red", "blue"),
       lty = c(1, 1, 2, 2), cex = 0.8)





### 4
Height = c(189, 193, 190, 191, 192, 188, 187, 191, 194, 194, 193, 182, 183,
           191, 192, 193, 195, 196, 189, 186, 188, 189, 185, 190, 184, 179,
           180, 178, 177, 175, 181, 179, 186, 175, 170, 175, 169, 165, 169,
           170, 173, 175, 184, 180, 182, 184, 183, 181, 178, 174)
Weight = c(89, 92, 90, 91, 93, 87, 90, 93, 96, 95, 94, 83, 84, 92, 92, 96, 94,
           97, 89, 84, 90, 92, 87, 92, 85, 85, 83, 84, 81, 78, 90, 81, 93, 84,
           78, 80, 74, 68, 72, 76, 78, 79, 88, 90, 94, 96, 95, 93, 82, 77)
Hips = c(112, 112, 110, 111, 113, 107, 112, 115, 115, 117, 116, 102, 101, 113,
         114, 115, 117, 118, 112, 111, 113, 114, 109, 113, 101, 123, 125, 128,
         123, 118, 113, 108, 113, 108, 105, 102, 96, 88, 84, 99, 102, 105,
         134, 140, 146, 152, 150, 149, 104, 112)
ShouldersWidth = c(40, 42, 39, 39, 40, 37, 40, 41, 42, 42, 41, 37, 38, 41, 42,
                   42, 43, 44, 40, 39, 40, 41, 40, 43, 37, 38, 39, 40, 42, 41,
                   39, 38, 40, 41, 38, 39, 40, 39, 43, 39, 42, 38, 39, 38, 41,
                   42, 39, 38, 43, 42)

### (1)
data <- data.frame(Height, Weight, Hips, ShouldersWidth);

model <- lm(Hips ~ Height + ShouldersWidth + Weight, data = data)

summary(model)

## (2)
coef(model)

## (3)
# За да определим дали има зависими фактори в модела, 
# можем да проверим корелационните коефициенти между факторите. 
# Ако някои фактори имат силна корелация (близка до 1 или -1), 
# това може да указва наличие на зависимост между тях.
cor(data)

## (4)
# Хипотези:
# H0: p-value (Pr(>|t|) тази колона) на коефициента е по-голям от 0.05 т.е. коефициентът е незначими
# H1 (алтернатива): p-value (Pr(>|t|) тази колона) на коефициента по-малко от 0.05 т.е. коефициентът е значим

# Друг вариант:
# Нулева хипотеза (H0): Коефициентът на даден фактор е нула (незначим);
# Алтернативна хипотеза (H1): Коефициентът на даден фактор е различен от нула (значим).


## (5)
# Статистиески значимите коефициенти са коефициентите за (Intercept), Height, Weight

## (6)
new_model <- step(model, direction = "backward")
summary(new_model)

## (7)
# hips = 218.8594 + Height * (-2.1668) + Weight * 3.3687

## (8)
residuals <- residuals(new_model)
head(residuals, 5)

## (9)
## (a)
residuals <- residuals(new_model)
shapiro.test(residuals)
# нормално разпределени са p-value = 0.2721 > 0.05

##(b)
t.test(residuals)

## (c)
anova_result <- anova(new_model)
anova_result
## (10)
# Стандартната грешка на модела е  8.356721

## (11)
## коефициента на детерминация e 0.6703259

## (12)
# За да се оцени дали модела е адекватем може да се базира на фактора,
# като коефициент на детерминация (R-squared),нормалното разпределение на грешката 
# и независимостта между грешките и значимите фактори
# В слуая R-squared = 0.6703 а Adjusted R-squared = 0.6563, за да бъде моделът
# по-адекватен е прието че колкото по близки до 1 са тези стойности толкова модела е
# по-добър в случая те не са мн близко до 1 и може да кажем че моделът не е много адекватен.
# За да се провери нормалното разпределение на грешката, можете да използвате статистически тест, 
# като например теста на Шапиро-Уилк. 
# Ако p-value на теста е по-голяма от зададеното ниво на значимост (например 0.05), 
# това указва, че няма значимо отклонение от нормалното разпределение на грешката. 
# Това е показател, че моделът може да бъде адекватен.
# За да с провери независимостта на грешките и значимите фактори, 
# можете да се изоплзва анализ на остатъчната вариация, например с помощта 
# на анализ на дисперсията (ANOVA). Ако p-value за значимите фактори 
# в ANOVA са по-големи от зададеното ниво на значимост (0.05), това указва, че няма 
# статистическа зависимост между грешките и значимите фактори. 
# Това подсказва, че моделът може да бъде адекватен
# Накратко обобщено според R-squared стойностите моделът не е адекватен

## (13)
expected_hips = 218.8594 + 173 * (-2.1668) + 85 * 3.3687
expected_hips
  
