/***************************************************************************
 * Copyright (C) 2014 by Renaud Guezennec                                   *
 * https://rolisteam.org/                                                *
 *                                                                          *
 *  This file is part of rcse                                               *
 *                                                                          *
 * rcse is free software; you can redistribute it and/or modify             *
 * it under the terms of the GNU General Public License as published by     *
 * the Free Software Foundation; either version 2 of the License, or        *
 * (at your option) any later version.                                      *
 *                                                                          *
 * rcse is distributed in the hope that it will be useful,                  *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of           *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the             *
 * GNU General Public License for more details.                             *
 *                                                                          *
 * You should have received a copy of the GNU General Public License        *
 * along with this program; if not, write to the                            *
 * Free Software Foundation, Inc.,                                          *
 * 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.                 *
 ***************************************************************************/
#ifndef FIELD_H
#define FIELD_H

#include <QFont>
#include <QMouseEvent>

#include "charactersheetitem.h"
#include "csitem.h"

#ifdef RCSE
#include "canvasfield.h"
#else
class CanvasField : public QGraphicsObject
{
    CanvasField();
};
#endif

/**
 * @brief The Field class managed text field in qml and datamodel.
 */
class Field : public CSItem
{
    Q_OBJECT
public:
    enum TextAlign
    {
        TopRight,
        TopMiddle,
        TopLeft,
        CenterRight,
        CenterMiddle,
        CenterLeft,
        BottomRight,
        BottomMiddle,
        BottomLeft
    };

    explicit Field(bool addCount= true, QGraphicsItem* parent= nullptr);
    explicit Field(QPointF topleft, bool addCount= true, QGraphicsItem* parent= nullptr);
    virtual ~Field();

    QSize size() const;
    void setSize(const QSize& size);

    QFont font() const;
    void setFont(const QFont& font);

    CharacterSheetItem* getChildAt(QString) const;

    virtual QVariant getValueFrom(CharacterSheetItem::ColumnId, int role) const;
    virtual void setValueFrom(CharacterSheetItem::ColumnId id, QVariant var);

    virtual void save(QJsonObject& json, bool exp= false);
    virtual void load(const QJsonObject& json, EditorController* ctrl);
    /**
     * @brief saveDataItem
     * @param json
     */
    virtual void saveDataItem(QJsonObject& json);
    /**
     * @brief load
     * @param json
     * @param scene
     */
    virtual void loadDataItem(const QJsonObject& json);

    virtual QPointF mapFromScene(QPointF);

    QStringList getAvailableValue() const;
    void setAvailableValue(const QStringList& availableValue);

    virtual CharacterSheetItem::CharacterSheetItemType getItemType() const;

    void copyField(CharacterSheetItem*, bool copyData, bool sameId= true);

    bool getClippedText() const;
    void setClippedText(bool clippedText);

    void setTextAlign(const TextAlign& textAlign);

    Field::TextAlign getTextAlignValue();

    virtual void setNewEnd(QPointF nend);

    CanvasField* getCanvasField() const;
    virtual void setCanvasField(CanvasField* canvasField);

    void initGraphicsItem();

    virtual qreal getWidth() const;
    virtual void setWidth(qreal width);

    virtual qreal getHeight() const;
    virtual void setHeight(qreal height);

    virtual void setX(qreal x);
    virtual qreal getX() const;

    virtual void setY(qreal x);
    virtual qreal getY() const;

    QString getGeneratedCode() const;
    void setGeneratedCode(const QString& generatedCode);

    bool getAliasEnabled() const;
    void setAliasEnabled(bool aliasEnabled);

    QPair<QString, QString> getTextAlign();
    bool isLocked() const;
public slots:
    void setLocked(bool b);
    void storeQMLCode();
signals:
    void updateNeeded(CSItem* c);

protected:
    void init();
    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent* ev);

protected:
    QFont m_font;
    TextAlign m_textAlign= CenterMiddle;
    QStringList m_availableValue;
    bool m_clippedText;
    CanvasField* m_canvasField;
    QString m_generatedCode;
    bool m_aliasEnabled= true;
    bool m_locked= false;
};

#endif // FIELD_H
