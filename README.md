# Problem Tanımı:
![uretici_tuketici](https://github.com/MustfaOzcan/IsletimSistemi/assets/103693735/3da8f14c-442f-42cf-ab7f-b1201341bccc)

Bu program, bir üretici-tüketici senaryosunu modellemektedir. Üretici, veri üretir ve paylaşılan belleğe yazar. Tüketici, bu paylaşılan belleği okur.
İki iş süreci (ebeveyn ve çocuk) arasında veri iletişimi sağlamak için bir Unix boru (pipe) kullanıyor. Pipe, ebeveyn sürecin yazdığı verilerin çocuk süreç tarafından okunmasını sağlar.
Ebeveyn süreç, bir boru oluşturur (pipe) ve bu boru üzerinden "Merhaba" metnini yazar. Ardından, paylaşılan belleğe bu metni yazar.
Çocuk süreç, aynı boruyu kullanarak "Merhaba" metnini okur ve ekrana yazar. Ayrıca, paylaşılan belleğe bu metni yazar.
Ebeveyn süreç, bu paylaşılan belleğe yazarken, çocuk süreç bu belleği okur ve ekrana yazar
# Ekran çıktısı 
https://github.com/MustfaOzcan/IsletimSistemi/assets/103693735/360dcf91-ee38-4ba3-82ce-59dadd1b5264


