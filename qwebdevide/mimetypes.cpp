#include "mimetypes.h"

MimeTypes::MimeTypes(QObject *parent) :
    QObject(parent)
{
    mimetypes_.insert("pdf",":/mimetypes/application-pdf.png");
    mimetypes_.insert("exe",":/mimetypes/application-x-ms-dos-executable.png");
    mimetypes_.insert("bmp",":/mimetypes/gnome-mime-image-bmp.png");
    mimetypes_.insert("tga",":/mimetypes/image-x-tga.png");
    mimetypes_.insert("txt",":/mimetypes/text-x-generic.png");
    mimetypes_.insert("cgm",":/mimetypes/gnome-mime-image-cgm.png");
    mimetypes_.insert("tiff",":/mimetypes/gnome-mime-image-tiff.png");
    mimetypes_.insert("ico",":/mimetypes/image-x-ico.png");
    mimetypes_.insert("java",":/mimetypes/text-x-java.png");
    mimetypes_.insert("ps",":/mimetypes/application-postscript.png");
    mimetypes_.insert("pl",":/mimetypes/application-x-perl.png");
    mimetypes_.insert("gif",":/mimetypes/gnome-mime-image-gif.png");
    mimetypes_.insert("svg",":/mimetypes/image-x-svg+xml.png");
    mimetypes_.insert("log",":/mimetypes/text-x-log.png");
    mimetypes_.insert("php",":/mimetypes/application-x-php.png");
    mimetypes_.insert("makefile",":/mimetypes/text-x-makefile.png");
    mimetypes_.insert("rar",":/mimetypes/application-x-rar.png");
    mimetypes_.insert("tar.bz",":/mimetypes/application-x-bzip-compressed-tar.png");
    mimetypes_.insert("jpeg",":/mimetypes/gnome-mime-image-jpeg.png");
    mimetypes_.insert("png",":/mimetypes/image-png.png");
    mimetypes_.insert("psd",":/mimetypes/gnome-mime-image-psd.png");
    mimetypes_.insert("gif",":/mimetypes/image-gif.png");
    mimetypes_.insert("ttf",":/mimetypes/font-x-generic.png");
    mimetypes_.insert("zip",":/mimetypes/application-zip.png");
    mimetypes_.insert("bzip",":/mimetypes/application-x-bzip.png");
    mimetypes_.insert("css",":/mimetypes/text-css.png");
    mimetypes_.insert("tar",":/mimetypes/application-x-compressed-tar.png");
    mimetypes_.insert("html",":/mimetypes/text-html.png");
    mimetypes_.insert("py",":/mimetypes/text-x-python.png");
    mimetypes_.insert("rtf",":/mimetypes/text-richtext.png");
    mimetypes_.insert("sql",":/mimetypes/text-x-sql.png");
    mimetypes_.insert("txt",":/mimetypes/text-x-readme.png");
    mimetypes_.insert("jar",":/mimetypes/application-x-jar.png");
    mimetypes_.insert("c",":/mimetypes/text-x-c.png");
    mimetypes_.insert("h",":/mimetypes/text-x-chdr.png");
    mimetypes_.insert("cpp",":/mimetypes/text-x-c++.png");
    mimetypes_.insert("xml",":/mimetypes/application-xml.png");

}

QString MimeTypes::iconForFileExt(QString fileExt)
{
    return mimetypes_.value(fileExt,":/mimetypes/unknown.png");
}
