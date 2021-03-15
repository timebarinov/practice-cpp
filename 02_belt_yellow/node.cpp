#include "node.h"

bool EmptyNode::Evaluate(const Date& date, const string& event) const {
    return true;
}

template <class T>
bool Compare(const Comparison& cmp, const T& left, const T& right) {
    switch (cmp) {
        case Comparison::Less:          return left <  right;
        case Comparison::LessOrEqual:   return left <= right;
        case Comparison::Equal:         return left == right;
        case Comparison::Greater:       return left >  right;
        case Comparison::GreaterOrEqual:return left >= right;
        case Comparison::NotEqual:      return left != right;
    }
    return false;
}

bool DateComparisonNode::Evaluate(const Date& date, const string& event) const {
    return Compare(cmp_, date, date_);
}

bool EventComparisonNode::Evaluate(const Date& date, const string& event) const {
    return Compare(cmp_, event, event_);
}

bool LogicalOperationNode::Evaluate(const Date& date, const string& event) const {
    if (operation_ == LogicalOperation::Or) {
        return (left_->Evaluate(date, event) || right_->Evaluate(date, event));
    } else {
        return (left_->Evaluate(date, event) && right_->Evaluate(date, event));
    }   
}
