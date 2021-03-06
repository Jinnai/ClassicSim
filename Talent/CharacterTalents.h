#pragma once

#include <QVector>

#include "TalentTree.h"

class CharacterTalents {
public:
    CharacterTalents();

    ~CharacterTalents();

    QString get_background_image(const QString& tree_position) const;
    QString get_icon(const QString& tree_position, const QString& talent_position) const;
    bool show_position(const QString& tree_position, const QString& talent_position) const;
    bool show_bottom_arrow(const QString& tree_position, const QString& talent_position) const;
    bool show_right_arrow(const QString& tree_position, const QString& talent_position) const;

    QString get_bottom_arrow(const QString& tree_position, const QString& talent_position) const;
    QString get_right_arrow(const QString& tree_position, const QString& talent_position) const;
    bool bottom_child_available(const QString& tree_position, const QString& talent_position) const;
    bool bottom_child_active(const QString& tree_position, const QString& talent_position) const;
    bool right_child_available(const QString& tree_position, const QString& talent_position) const;
    bool right_child_active(const QString& tree_position, const QString& talent_position) const;
    bool is_active(const QString& tree_position, const QString& talent_position) const;
    bool is_available(const QString& tree_position, const QString& talent_position) const;
    bool is_maxed(const QString& tree_position, const QString& talent_position) const;
    bool has_talent_points_remaining() const;
    QString get_rank(const QString& tree_position, const QString& talent_position) const;
    QString get_max_rank(const QString& tree_position, const QString& talent_position) const;
    bool increment_rank(const QString& tree_position, const QString& talent_position);
    bool decrement_rank(const QString& tree_position, const QString& talent_position);
    QString get_requirements(const QString& tree_position, const QString& talent_position) const;
    QString get_current_rank_description(const QString& tree_position, const QString& talent_position) const;
    QString get_next_rank_description(const QString& tree_position, const QString& talent_position) const;
    int get_tree_points(const QString& tree_position) const;
    QString get_tree_name(const QString& tree_position) const;
    QString get_talent_name(const QString& tree_position, const QString& talent_position) const;
    QString get_talent_position(const QString& tree_position, const QString& talent_name) const;
    void increase_to_max_rank(const QString& tree_position, const QString& talent_position);
    void decrease_to_min_rank(const QString& tree_position, const QString& talent_position);

    void clear_tree(const QString& tree_position);
    void set_current_index(const int index);

    void add_talent_tree(TalentTree *left_tree, TalentTree* mid_tree, TalentTree *right_tree);

    int get_talent_points_remaining() const;

    QVector<QPair<QString, QVector<QPair<QString, QString>>>> get_current_talent_setup() const;

private:
    QVector<QMap<QString, TalentTree*>> talent_trees;

    int current_index;
    QVector<int> talent_points_remaining;
};
