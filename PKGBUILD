# Maintainer: Artem Bebik <echo YXJ0ZW1AYmVieXguY28udWEK | base64 -d>

pkgname='quotix'
pkgver='0.2.1'
pkgrel=1

pkgdesc="Quotix (qtx) is a suckless random quote C program, prints out a random line from a plain text file."
arch=('x86_64')
url="https://github.com/bebyx/${pkgname}"
license=('GPL3')

depends=()
makedepends=('make' 'gcc')
checkdepends=()
optdepends=()
provides=('quotix')
conflicts=('quotix')
source=("git+https://github.com/bebyx/${pkgname}.git")
sha256sums=('SKIP')

build() {
    cd "$pkgname"
    make
}

check() {
    cd "$pkgname"
    make check
}

package() {
    cd "$pkgname"
    make binpath="$pkgdir/usr/local/bin" datapath="$pkgdir/usr/local/share" install
}
