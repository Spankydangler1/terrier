#pragma once

#include <memory>
#include <utility>
#include <vector>
#include "parser/expression/abstract_expression.h"
#include "parser/expression_defs.h"
#include "type/type_id.h"

namespace terrier::parser {

/**
 * Represents a logical comparison expression.
 */
class ComparisonExpression : public AbstractExpression {
 public:
  /**
   * Instantiates a new comparison expression.
   * @param cmp_type type of comparison
   * @param children vector containing exactly two children, left then right
   */
  ComparisonExpression(const ExpressionType cmp_type, std::vector<std::shared_ptr<AbstractExpression>> &&children)
      : AbstractExpression(cmp_type, type::TypeId::BOOLEAN, std::move(children)) {}

  /**
   * Default constructor for deserialization
   */
  ComparisonExpression() = default;

  std::shared_ptr<AbstractExpression> Copy() const override { return std::make_shared<ComparisonExpression>(*this); }

  /**
   * @return expression serialized to json
   */
  nlohmann::json ToJson() const override {
    nlohmann::json j = AbstractExpression::ToJson();

    return j;
  }

  /**
   * @param j json to deserialize
   */
  void FromJson(const nlohmann::json &j) override { AbstractExpression::FromJson(j); }
};

DEFINE_JSON_DECLARATIONS(ComparisonExpression);

}  // namespace terrier::parser
