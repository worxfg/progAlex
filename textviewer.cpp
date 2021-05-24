#include "textviewer.h"
#include <iostream>
#include "montagne.h"
#include "champpotentiels.h"
#include "ciel.h"
#include "systeme.h"

using namespace std;

void TextViewer::dessine(const Systeme &a_dessiner)
{
    cout<<a_dessiner;
}

void TextViewer::dessine(const Montagne &a_dessiner)
{
    cout<<a_dessiner;
}

void TextViewer::dessine(const ChampPotentiels &a_dessiner)
{
    cout<<a_dessiner;
}

void TextViewer::dessine(const Ciel &a_dessiner)
{
    cout<<a_dessiner;
}
